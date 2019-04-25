/*************************************************************************
	> File Name: 110.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年
 ************************************************************************/

/*
 * Problem:
 *
 * Given a binary tree, determine if it is height-balanced.
 * For this problem, a height-balanced binary tree is defined as:
 * 
 * Tips: a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
    return a > b ? a : b;
}

int maxDepth(struct TreeNode *root) {
    if (root == NULL) return 0;
    int d1 = maxDepth(root->left);
    int d2 = maxDepth(root->right);
    if (d1 == -2 || d2 == -2 || abs(d1 - d2) > 1) return -2;
    return fmax(d1, d2) + 1;
}

bool isBalanced(struct TreeNode* root) {
    return maxDepth(root) >= 0;
}

int main() {
    printf(".cpp\n");
    return 0;
}
