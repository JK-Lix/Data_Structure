/*************************************************************************
	> File Name: 235.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年
 ************************************************************************/

/*
 * Problem:
 *
 * Given a binary search tree (BST), find the lowest common ancestor (LCA)
 * of two given nodes in the BST.According to the definition of LCA on 
 * Wikipedia: “The lowest common ancestor is defined between two nodes 
 * p and q as the lowest node in T that has both p and q as descendants
 * (where we allow a node to be a descendant of itself).”
 *
 * Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]
 *
 */


#include<stdio.h>
#include<stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int swap(struct TreeNode** p, struct TreeNode **q) {
    if ((*p)->val <= ((*q)->val)) return 0;
    struct TreeNode *temp = *p;
    *p = *q;
    *q = temp;
    return 1;
}
struct TreeNode* __lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root->val == p->val) return p;
    if (root->val == q->val) return q;
    if (p->val < root->val && q->val < root->val) return root;
    if (p->val > root->val) return __lowestCommonAncestor(root->right, p, q);
    return __lowestCommonAncestor(root->left, p, q);
}
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL) return NULL;
    if (p->val == q->val) return p;
    if (p->val > q->val) {
        struct TreeNode *temp = p;
        p = q;
        q = temp;
    }
    return __lowestCommonAncestor(root, p, q);
}

int main() {
    printf("235.cpp\n");
    return 0;
}
