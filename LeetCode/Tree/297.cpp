/*************************************************************************
	> File Name: 297.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年
 ************************************************************************/

/*
 * Problem:
 *
 * Serialization is the process of converting a data structure or object 
 * into a sequence of bits so that it can be stored in a file or memory 
 * buffer, or transmitted across a network connection link to be 
 * reconstructed later in the same or another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary tree. There 
 * is no restriction on how your serialization/deserialization algorithm 
 * should work. You just need to ensure that a binary tree can be 
 * serialized to a string and this string can be deserialized to the 
 * original tree structure.
 *
 */


#include<stdio.h>
#include<stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct Queue {
    struct TreeNode* *data;
    int head, tail, length, count;
} Queue;

Queue *init() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 100000);
    q->length = 100000;
    q->count = 0;
    q->head = q->tail = 0;
    return q;
}

struct TreeNode* front(Queue *q) {
    return q->data[q->head];
}

int empty(Queue *q) {
    return q->count == 0;
}

void push(Queue *q, struct TreeNode* val) {
    if (q->count == q->length) return;
    q->data[(q->tail)++] = val;
    if (q->tail >= q->length) q->tail -= q->length;
    q->count += 1;
    return;
}

void pop(Queue *q) {
    q->head += 1;
    if (q->head >= q->length) q->head -= q->length;
    q->count -= 1;
    return;
}

void clear(Queue *q) {
    if (q == NULL) return;
    free(q->data);
    free(q);
    return;
}

int count;
int max_depth(struct TreeNode* root) {
    if (root == NULL) return 0;
    count++;
    int ld = max_depth(root->left);
    int rd = max_depth(root->right);
    return (ld > rd ? ld : rd) + 1;
}

int getNum(char *ch) {
    int val = 0, i = 0;
    int len = strlen(ch) - 1;
    if (ch[0] == '-') {
        i = 1;
        ch[0] = 0;
    }
    for (; i <= len; i++) {
        val += (ch[i] - '0') * pow(10, len - i);
    }
    if (!ch[0]) val = 0 - val;
    return val;
}

char* serialize(struct TreeNode* root) {
    int deep = max_depth(root);
    unsigned long long size = pow(2, deep) - 1;
    char *data = (char*)calloc(400000, sizeof(char));
    Queue *q = init();
    sprintf(data, "%s[", data);
    if (root == NULL) {
        sprintf(data, "%s]", data);
        return data;
    }
    push(q, root);
    struct TreeNode *null = NULL;
    while(!empty(q)) {
        struct TreeNode *node = front(q);
        if (node == NULL) {
            sprintf(data,"%snull,",data);
            pop(q);
            size -= 1;
            if (size < 1) break;
            else continue;
        }
        else sprintf(data,"%s%d,",data, node->val);
        count--;
        push(q, node->left);
        push(q, node->right);
        pop(q);
        size -= 1;
        if (size < 3 && count == 0) break;
        if (size < 1) break;
    }
    clear(q);
    data[strlen(data) - 1] = ']';
    return data;
}

struct TreeNode* getNewNode(int val) {
    struct TreeNode* p = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (val == -999999) return NULL;
    p->val = val;
    p->left = p->right = NULL;
    return p;
}

void createTree(struct TreeNode* root, Queue *q, int *node, int i) {
    int cnt = 1;
    while(cnt < i) {
        struct TreeNode* temp = front(q);
        pop(q);
        temp->left = getNewNode(node[cnt++]);
        if (temp->left != NULL) push(q, temp->left);
        if (cnt >= i) break;
        temp->right = getNewNode(node[cnt++]);
        if (temp->right != NULL) push(q, temp->right);
        if (cnt >= i) break;
    }
}

/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data) {
    int i = 0;
    int node[1000000] = {0};
    data[0] = ',';
    data[strlen(data) - 1] = ',';
    char *ch = strtok(data, ",");
    while(ch != NULL) {
        node[i++] = (!strcmp(ch, "null")) ? -999999 : getNum(ch);
        ch = strtok(NULL, ",");
    }
    if (i == 0) return NULL;
    Queue *q = init();
    struct TreeNode *root = getNewNode(node[0]);
    push(q, root);
    createTree(root, q, node, i);
    return root;
}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);


int main() {
    printf("297.cpp\n");
    return 0;
}
