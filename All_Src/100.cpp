/*************************************************************************
	> File Name: 100.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年
 ************************************************************************/

/*
 * Problem:
 *
 * Given two binary trees, write a function to check if they are the same 
 * or not.
 * 
 * Two binary trees are considered the same if they are structurally 
 * identical and the nodes have the same value.
 *
 */


#include<stdio.h>
#include<stdlib.h>

 struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p->val - q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    printf("100.cpp\n");
    return 0;
}
