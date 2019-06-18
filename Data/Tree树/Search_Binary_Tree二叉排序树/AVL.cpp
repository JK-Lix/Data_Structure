/*************************************************************************
	> File Name: AVL.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年05月25日 星期六 16时54分03秒
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<climits>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;

typedef struct Node {
    int key, h;
    struct Node *r, *l;
} Node;

Node __NIL;
#define NIL (&__NIL)

__attribute__((constructor))
void init_NIL() {
    NIL->h = NIL->key = 0;
    NIL->r = NIL->l = NULL;
}

Node *getNewNode (int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->h = 1;
    p->l = p->r = NIL;
    return p;
}

void calc_height(Node *root) {
    int l = root->l->h;
    int r = root->r->h;
    root->h = (l > r ? l : r) + 1;
    return;
}

Node *left_rotate(Node *root) {
    Node *temp = root->r;
    root->r = temp->l;
    temp->l = root;
    calc_height(root);
    calc_height(temp);
    return temp;
}

Node *right_rotate(Node *root) {
    Node *temp = root->l;
    root->l = temp->r;
    temp->r = root;
    calc_height(root);
    calc_height(temp);
    return temp;
}

Node *maintain(Node *root) {
    if (abs(root->l->h - root->r->h) <= 1) return root;
    if (root->l->h > root->r->h) {
        if (root->l->r->h > root->l->l->h) {
            root->l = left_rotate(root->l);
        }
        root = right_rotate(root);
    } else {
        if (root->r->l->h > root->r->r->h) {
            root->l = right_rotate(root->l);
        }
        root = left_rotate(root);
    }
}

Node *insert(Node *root, int key) {
    if (root == NIL) return getNewNode(key);
    if (root->key == key) return root;
    if (key < root->key) root->l = insert(root->l, key);
    else root->r = insert(root->r, key);
    calc_height(root);
    return maintain(root);
}

Node *predecessor(Node *root) {
    Node *temp = root->l;
    while (temp->r != NIL) temp = temp->r;
    return temp;
}

Node *erase(Node *root, int key) {
    if (root == NIL) return root;
    if (key < root->key) {
        root->l = erase(root->l, key);
    } else if (key > root->key) {
        root->r = erase(root->r, key);
    } else {
        if (root->l == NIL && root->r == NIL) {
            free(root);
            return NIL;
        }
        if (root->l == NULL || root->r == NULL) {
            Node *temp = root->l != NIL ? root->l : root->r;
            free(root);
            return temp;
        }
        Node *temp = predecessor(root);
        root->key = temp->key;
        root->l = erase(root->l, temp->key);
    }
    calc_height(root);
    return maintain(root);
}

void clear(Node *root) {
    if (root == NIL) return;
    clear(root->l);
    clear(root->r);
    free(root);
    return;
}

void output(Node *root) {
    if (root == NIL) return;
    printf("(%d %d %d)\n", root->key, root->l->key, root->r->key);
    output(root->l);
    output(root->r);
}

int main() {
    int op, val;
    Node *root = NIL;
    while (~scanf("%d%d", &op, &val)) {
        switch(op) {
            case 1: {
                root = insert(root, val);
            } break;
            case 2: {
                root = erase(root, val);
            }break;
        }
        output(root);
    }
    return 0;
}
