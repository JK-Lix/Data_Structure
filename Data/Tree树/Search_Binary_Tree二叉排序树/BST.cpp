/*************************************************************************
	> File Name: BST.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年05月25日 星期六 15时01分53秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *l, *r;
} Node;

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = val;
    p->l = p->r = NULL;
    return p;
}

Node *insert(Node *root, int val) {
    if (root == NULL) return getNewNode(val);
    if (root->key == val) return root;
    if (root->key < val) {
        root->r = insert(root->r, val);
    } else {
        root->l = insert(root->l, val);
    }
    return root;
}

Node *predecessor(Node *root) {
    Node *temp = root->l;
    while (temp->r) temp = temp->r;
    return temp;
}

Node *erase(Node *root, int val) {
    if (root == NULL) return NULL;
    if (root->key > val) {
        root->l = erase(root->l, val);
    } else if (root->key < val) {
        root->r = erase(root->r, val);
    } else {
        if (root->l == NULL && root->r == NULL) {
            free(root);
            return NULL;
        } else if (root->l == NULL || root->r == NULL) {
            Node *temp = root->l ? root->l : root->r;
            free(root);
            return temp;
        }
        Node *temp = predecessor(root);
        root->key = temp->key;
        root->l = erase(root->l, temp->key);
    }
}

void clear(Node *root) {
    if (root == NULL) return;
    clear(root->l);
    clear(root->r);
    free(root);
    return;
}

void output(Node *root) {
    if (root == NULL) return;
    int lval = root->l ? root->l->key : 0;
    int rval = root->r ? root->r->key : 0;
    printf("(%d, lval: %d, rval: %d)\n", root->key, lval, rval);
    output(root->l);
    output(root->r);
    return;
}

int main() {
    int op, val;
    Node *root = NULL;
    while (~scanf("%d%d", &op, &val)) {
        switch(op) {
            case 1: {
                root = insert(root, val);
            } break;
            case 2: {
                root = erase(root, val);
            } break;
        }
        output(root);
    }
    return 0;
}

