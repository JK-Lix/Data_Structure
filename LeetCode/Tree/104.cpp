/*************************************************************************
	> File Name: 104.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年
 ************************************************************************/

/*
 * Problem:
 *
 * Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path from 
 * the root node down to the farthest leaf node.
 *
 */


#include<stdio.h>
#include<stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int deeps(struct TreeNode* root, int deep) {
    if (root == NULL) return deep;
    int a = deeps(root->left, deep + 1);
    int b = deeps(root->right, deep + 1);
    return a > b ? a : b;
}

int maxDepth(struct TreeNode* root) {
    return deeps(root, 0);
}

int main() {
    printf("104.cpp\n");
    return 0;
}
