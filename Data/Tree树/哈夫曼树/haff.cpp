/*************************************************************************
	> File Name: haff.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年04月27日 星期六 16时06分33秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define swap(a, b) {\
                    __typeof(a) temp = a;\
                    a = b; b = temp;\
                   }

typedef struct Data {
    char ch;
    int freq;
} Data;

typedef struct Node {
    Data d;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(Data val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->lchild = p->rchild = NULL;
    p->d = val;
    return p;
}

Node *build_huffman(Data *data, int n) {
    Node **arr = (Node **)malloc(sizeof(Node *) * n);
    for (int i = 0; i < n; i++) arr[i] = getNewNode(data[i]);
    int ind1 = 1, ind2 = 1, r1, r2;
    for (int i = 0; i < n - 1; i++) {
        r1 = n - i - 1, r2 = n - i - 2;
        if (arr[r1]->d.freq > arr[r2]->d.freq) swap(arr[r1], arr[r2]);
        ind1 = 1, ind2 = 0;
        if (arr[ind1]->d.freq > arr[ind2]->d.freq) swap(ind1, ind2);
        for (int j = 2; j < n - i; j++) {
            if (arr[j]->d.freq < arr[ind1]->d.freq) {
                ind2 = ind1, ind1 = j;
            } else if (arr[j]->d.freq < arr[ind2]->d.freq) {
                ind2 = j;
            }
        }
        if (ind2 - r2) swap(arr[ind2], arr[r2]);
        if (ind1 - r1) swap(arr[ind1], arr[r1]);
        Node *new_node = getNewNode({0, arr[r1]->d.freq + arr[r2]->d.freq});
        new_node->lchild = arr[r1];
        new_node->rchild = arr[r2];
        arr[r2] = new_node;
    } 
    Node *root = arr[0];
    free(arr);
    return root;
}

void clear(Node *node) {
    if (node == NULL) return ;
    clear(node->lchild);
    clear(node->rchild);
    free(node);
    return ;
}

void preorder(Node *root) {
    if (root == NULL) {
        printf("null ");
        return ;
    }
    printf("%c ", (root->d.ch == 0 ? '0' : root->d.ch));
    preorder(root->lchild);
    preorder(root->rchild);
    return ;
}

void extract_huffman_code(Node *root, char **code, char *buff, int k) {
    if (root->lchild == NULL && root->rchild == NULL) {
        buff[k] = 0;
        code[root->d.ch] = strdup(buff);
        return ;
    }
    buff[k] = '0'; extract_huffman_code(root->lchild, code, buff, k + 1);
    buff[k] = '1'; extract_huffman_code(root->rchild, code, buff, k + 1);
    return ;
}

int main() {
    int n, freq;
    char str[100];
    char *code[256] = {0};
    Data data[256];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s%d", str, &freq);
        data[i] = {str[0], freq};
    }
    Node *root = build_huffman(data, n);
    extract_huffman_code(root, code, str, 0);
    preorder(root), printf("\n");
    for (int i = 0; i < 256; i++) {
        printf("%c\n", i);
        if (code[i]) printf("%c = %s\n", i, code[i]);
    }
    clear(root);
    return 0;
}
