/*************************************************************************
	> File Name: 111.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年
 ************************************************************************/

/*
 * Problem:
 *
 * Given a binary tree, find its minimum depth.
 * The minimum depth is the number of nodes along the shortest path from 
 * the root node down to the nearest leaf node.
 *
 */


#include<stdio.h>
#include<stdlib.h>

int fmin(int a, int b) {
    return a < b ? a : b;
}

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int minDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    if (root->left == NULL || root->right == NULL)
        return minDepth(root->right ? root->right : root->left) + 1;
    return fmin(minDepth(root->left), minDepth(root->right)) + 1;
}

int main() {
    printf("111.cpp\n");
    return 0;
}
