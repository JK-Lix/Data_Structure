/*************************************************************************
	> File Name: 101.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年
 ************************************************************************/

/*
 * Problem:
 *
 * Given a binary tree, check whether it is a mirror of itself 
 * (ie, symmetric around its center).
 *
 */


#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isMirror(struct TreeNode *p, struct TreeNode *q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p->val - q->val) return false;
    return isMirror(p->left, q->left) && isMirror(p->right, q->right);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) return  true;
    return isMirror(root, root);
}

int main() {
    printf("101.cpp\n");
    return 0;
}
