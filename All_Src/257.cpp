/*************************************************************************
	> File Name: 257.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年
 ************************************************************************/

/*
 * Problem:
 *
 * Given a binary tree, return all root-to-leaf paths.
 * Note: A leaf is a node with no children.
 *
 */


#include<stdio.h>
#include<stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int getPathCnt(struct TreeNode *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return getPathCnt(root->left) + getPathCnt(root->right);
}

int getPathLen(struct TreeNode *root, int k, int cnt, int *len) {
    if (root == NULL) return 0;
    static char str[30];
    k += sprintf(str, "%d", root->val);
    if (root->left == NULL && root->right == NULL) {
        len[cnt] = k;
        return 1;
    }
    int delta = 0;
    k += 2;
    delta += getPathLen(root->left, k, cnt + delta, len);
    delta += getPathLen(root->right, k, cnt + delta, len);
    return delta;
}

int getData(struct TreeNode *root, char **ret, int cnt, char *buff, int ind) {
    if (root == NULL) return 0;
    ind += sprintf(buff + ind, "%d", root->val), buff[ind] = 0;
    if (root->left == NULL && root->right == NULL) {
        strcpy(ret[cnt], buff);
        return 1;
    }
    int delta = 0;
    ind += sprintf(buff + ind, "->"), buff[ind] = 0;
    delta += getData(root->left, ret, cnt + delta, buff, ind);
    delta += getData(root->right, ret, cnt + delta, buff, ind);
    return delta;
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL) return NULL;
    int n = getPathCnt(root), maxLen = 0;
    char **ret = (char **)malloc(sizeof(char *) * n);
    int *len = (int *)malloc(sizeof(int) * n);
    getPathLen(root, 0, 0, len);
    for (int i = 0; i < n; i++) {
        ret[i] = (char *)malloc(sizeof(char) * (len[i] + 1));
        maxLen = fmax(maxLen, len[i]);
    }
    char *buff = (char *)malloc(sizeof(char) * (maxLen + 1));
    getData(root, ret, 0, buff, 0);
    *returnSize = n;
    return ret;
}

int main() {
    printf("257.cpp\n");
    return 0;
}
