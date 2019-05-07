/*************************************************************************
	> File Name: .cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年
 ************************************************************************/

/*
 * Problem:
 *
 *
 *
 */


#include<stdio.h>
#include<stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int k;
int depth;
int max_depth(struct TreeNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) k++;
    int ld = max_depth(root->left);
    int rd = max_depth(root->right);
    return (ld > rd ? ld : rd) + 1;
}

void search(struct TreeNode* root, char **ret, char *buf, int dp) {
    if (root == NULL) return;
    char *buff = (char*)malloc(sizeof(char) * dp * 10);
    strcpy(buff, buf);
    if (!root->left && !root->right) {
        sprintf(buff, "%s%d", buff, root->val);
        strcpy(ret[--k], buff);
        free(buff);
        return;
    }
    else sprintf(buff, "%s%d->", buff, root->val);
    if (root->left) search(root->left, ret, buff, dp + 1);
    if (root->right) search(root->right, ret, buff, dp + 1);
    free(buff);
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    depth = max_depth(root);
    char** ret = (char**)malloc(sizeof(char*) * k);
    *returnSize = k;
    for (int i = 0; i < k; i++) {
          ret[i] = (char *)malloc(sizeof(char) * (depth * 10));
    }
    char *buf = (char*)malloc(sizeof(char) * 2);
    for (int i = 0; i < 2; i++) {
        buf[i] = 0;
    }
    search(root, ret, buf, 1);
    free(buf);
    return ret;
}

int main() {
    printf(".cpp\n");
    return 0;
}
