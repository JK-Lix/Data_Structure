/*************************************************************************
	> File Name: trans.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年04月27日 星期六 14时19分55秒
 ************************************************************************/

//广义表转二叉树

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Node {
    int key;
    struct Node *lchild, *rchild;
} Node;

typedef struct Stack {
    int top, size;
    Node **data;
} Stack;

Stack* initStack(int n) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->data = (Node**)malloc(sizeof(Node*) * n);
    s->top = -1;
    s->size = n;
    return s;
}

int emptyStack(Stack *s) {
    return s->top == -1;
}

void pushStack(Stack* s, Node* node) {
    if (s->top + 1 >= s->size) return;
    s->data[++(s->top)] = node;
    return;
}

void popStack(Stack* s) {
    if (emptyStack(s)) return;
    --(s->top);
}

Node* topStack(Stack* s) {
    if (emptyStack(s)) return NULL;
    return s->data[s->top];
}

void clearStack(Stack* s) {
    if (s == NULL) return;
    free(s->data);
    free(s);
    return;
}

Node* getNewNode(int val) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->lchild = p->rchild = NULL;
    p->key = val;
    return p;
}

Node* build(const char* str) {
    int len = strlen(str);
    Stack* s = initStack(len);
    int status = 0, k = 0;
    Node* p = NULL;
    while (str[0]) {
        switch(status) {
            case 0: {
                if (str[0] <= '9' && str[0] >= '0') {
                    status = 1;
                } else if (str[0] == '(') {
                    status = 2;
                } else if (str[0] == ',') {
                    status = 3;
                } else if (str[0] == ')') {
                    status = 4;
                } else {
                    str++;
                }
            } break;
            case 1: {
                if (p == NULL) p = getNewNode(0);
                if (k == 0 && !emptyStack(s)) {
                    topStack(s)->lchild = p;
                } else if(k == 1 && !emptyStack(s)) {
                    topStack(s)->rchild = p;
                }
                if (str[0] <= '9' && str[0] >= '0') {
                    p->key = p->key * 10 + str[0] - '0';
                    str++;
                } else {
                    status = 0;
                }
            } break;
            case 2: {
                pushStack(s, p);
                k = 0;
                p = NULL;
                status = 0;
                str++;
            } break;
            case 3: {
                k = 1;
                p = NULL;
                status = 0;
                str++;
            } break;
            case 4: {
                p = topStack(s);
                popStack(s);
                status = 0;
                str++;
            }break;
        }
    }
    return p;
}

void clear(Node* node) {
    if (node == NULL) return;
    clear(node->lchild), clear(node->rchild);
    free(node);
    return;
}

void preoder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->key);
    preoder(root->lchild);
    preoder(root->rchild);
    return;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->lchild);
    printf("%d ", root->key);
    inorder(root->rchild);
    return;
}

int main() {
    char str[100];
    while(~scanf("%s", str)) {
        Node* root = build(str);
        inorder(root), printf("\n");
        preoder(root), printf("\n");
    }
    return 0;
}
