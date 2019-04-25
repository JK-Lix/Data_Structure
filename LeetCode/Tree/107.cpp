/*************************************************************************
	> File Name: 107.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年
 ************************************************************************/

/*
 * Problem:
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
 *
 */


#include<stdio.h>
#include<stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int fmax(int a, int b) {
    return (a > b ? a : b);
}

int getDepth(struct TreeNode *root) {
    if (root == NULL) return 0;
    int d1 = getDepth(root->left);
    int d2 = getDepth(root->right);
    return fmax(d1, d2) + 1;
}

void getSize(struct TreeNode *root, int k, int *size) {
    if (root == NULL) return;
    size[k] += 1;
    getSize(root->left, k - 1, size);
    getSize(root->right, k - 1, size);
    return;
}

void getData(struct TreeNode *root, int **ret, int *size, int k) {
    if (root == NULL) return;
    ret[k][size[k]++] = root->val;
    getData(root->left, ret, size, k - 1);
    getData(root->right, ret, size, k - 1);
    return;
}

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    int n = getDepth(root);
    int **ret = (int **)malloc(sizeof(int *) * n);
    int *size = (int *)calloc(sizeof(int), n);
    getSize(root, n - 1, size);
    for (int i = 0; i < n; i++) {
        ret[i] = (int *)malloc(sizeof(int) * size[i]);
        size[i] = 0;
    }
    getData(root, ret, size, n - 1);
    *returnSize = n;
    *returnColumnSizes = size;
    return ret;
}


int main() {
    printf("107.cpp\n");
    return 0;
}
