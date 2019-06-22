/*************************************************************************
	> File Name: RBT.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年06月22日 星期六 16时10分34秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int key, color; // 0 red, 1 black, 2 very black
    struct Node *lchild, *rchild;
} Node;

#define RED_COLOR 0
#define BLACK_COLOR 1
#define VERY_BLACK 2

Node __NIL;
#define NIL (&__NIL)

__attribute__((constructor))
void init_NIL() {
    NIL->key = 0;
    NIL->color = BLACK_COLOR;
    NIL->lchild = NIL->rchild = NIL;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->lchild = p->rchild = NIL;
    p->key = key;
    p->color = RED_COLOR;
    return p;
}

int has_red_child (Node *root) {
    return (root->lchild->color == 0 || root->rchild->color == 0);
}

Node *left_rotate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    return temp;
}

Node *right_rotate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    return temp;
}

Node *insert_maintain(Node *root) {
    if (!has_red_child(root)) return root;
    printf("bbb\n");
    if (root->lchild->color == RED_COLOR && root->rchild->color == RED_COLOR) {
        if (root->rchild->color == RED_COLOR) {
            root->color = RED_COLOR;
            root->lchild->color = root->rchild->color = BLACK_COLOR;
            return root;
        }
    }
    if (has_red_child(root->lchild) && root->lchild->color == RED_COLOR) {
        if (root->lchild->rchild->color == RED_COLOR) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
        root->color = RED_COLOR;
        root->lchild->color = root->rchild->color = BLACK_COLOR;
    } else if (has_red_child(root->rchild) && root->rchild->color == RED_COLOR) {
        if (root->rchild->lchild->color == RED_COLOR) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
        root->color = RED_COLOR;
        root->lchild->color = root->rchild->color = BLACK_COLOR;
    }
    return root;
}


Node *__insert(Node *root, int val) {
    if (root == NIL) return getNewNode(val);
    if (root->key == val) return root;
    if (root->key < val) root->rchild = __insert(root->rchild, val);
    else {
        root->lchild = __insert(root->lchild, val);
    }
    return insert_maintain(root);
}

Node *insert(Node *root, int val) {
    root = __insert(root, val);
    root->color = BLACK_COLOR;
    return root;
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *erase_maintain(Node *root) {
    if (root->lchild->color != VERY_BLACK && root->rchild->color != VERY_BLACK) 
        return root;
    if (has_red_child(root)) {
        Node *temp = root;
        root->color = RED_COLOR;
        if (root->lchild->color == RED_COLOR) root = right_rotate(root);
        else root = left_rotate(root);
        root->color = BLACK_COLOR;
        if (temp == root->lchild) root->lchild = erase_maintain(temp);
        else root->rchild = erase_maintain(temp);
    } else if (root->lchild->color == BLACK_COLOR) {
        if (!has_red_child(root->lchild)) {
            root->color += 1;
            root->lchild->color -= 1, root->rchild->color -= 1;
            return root;
        }
        if (root->lchild->lchild->color != RED_COLOR) {
            root->color = RED_COLOR;
            root->lchild = left_rotate(root->lchild);
            root->color = BLACK_COLOR;
        }
        root->rchild->color -= 1;
        root = right_rotate(root);
        root->lchild->color = root->rchild->color;
    } else {
        if (!has_red_child(root->rchild)) {
            root->color += 1;
            root->lchild->color -= 1, root->rchild->color -=1;
            return root;
        }
        if (root->rchild->rchild->color != RED_COLOR) {
            root->color = RED_COLOR;
            root->rchild = right_rotate(root->rchild);
            root->color = BLACK_COLOR;
        }
        root->lchild->color -= 1;
        root = left_rotate(root);
        root->rchild->color = root->lchild->color;
    }
    return root;
}

Node *__erase(Node *root, int val) {
    if (root == NIL) return root;
    if (val < root->key) {
        root->lchild = __erase(root->lchild, val);
    } else if (val > root->key) {
        root->rchild = __erase(root->rchild, val);
    } else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *p = (root->lchild == NIL ? root->rchild : root->lchild);
            p->color += root->color;
            free(root);
            return p;
        } else {
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = __erase(root->lchild, temp->key);
        }
    }
    return erase_maintain(root);
}

Node *erase(Node *root, int val) {
    root = __erase(root, val);
    root->color = BLACK_COLOR;
    return root;
}

void clear(Node *node) {
    if (node == NIL) return;
    clear(node->lchild);
    clear(node->rchild);
    free(node);
    return;
}

void output(Node *root) {
    if (root == NIL) return;
    printf("(%d | %d, %d, %d)\n", 
           root->color, 
           root->key, 
           root->lchild->key,
           root->rchild->key
          );
    output(root->lchild);
    output(root->rchild);
}

int main() {
    Node *root = NIL;
    int op, val;
    while (~scanf("%d%d", &op, &val)) {
        switch (op) {
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

