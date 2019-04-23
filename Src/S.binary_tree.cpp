/*************************************************************************
	> File Name: S.binary_tree.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年04月14日 星期日 20时24分56秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int key;
    struct Node *lchild, *rchild;
} Node;


Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NULL;
    return p;
}

void postorder(Node *tree) {
    if (tree == NULL) return;
    postorder(tree->lchild);
    postorder(tree->rchild);
    printf("%d ",tree->key);
    return;
}


void inorder(Node *tree) {
    if (tree == NULL) return;
    inorder(tree->lchild);
    printf("%d ", tree->key);
    inorder(tree->rchild);
    return;
}

void preorder(Node *tree) {
    if (tree == NULL) return;
    printf("%d ", tree->key);
    preorder(tree->lchild);
    preorder(tree->rchild);
    return;
}


//二叉排序树节点的添加，可能会替代原有根节点
Node *insert(Node *tree, int val) {
    if (tree == NULL) return getNewNode(val);
    if (tree->key == val) return tree;
    if (tree->key > val) tree->lchild = insert(tree->lchild, val);
    else tree->rchild = insert(tree->rchild, val);
    return tree;
}

void clear(Node *tree) {
    if (tree == NULL) return;
    clear(tree->lchild);
    clear(tree->rchild);
    free(tree);
    return;
}


int main() {
    #define MAX_OP 20
    srand(time(0));
    Node *root = NULL;
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        printf("insert %d to binary search tree\n", val);
        root = insert(root, val);
        printf("pre_order  = "), preorder(root), printf("\n");
        printf("in_order   = "), inorder(root), printf("\n");
        printf("post_order = "), postorder(root), printf("\n");
    }
    return 0;
}
