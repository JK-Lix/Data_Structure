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
 * Given a binary tree, return the level order traversal of its nodes' 
 * values. (ie, from left to right, level by level).
 *
 */


#include<stdio.h>
#include<stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, 
 * assume caller calls free().
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct Data {
    int dep, size, *depSize;
} Data;

Data *initData(struct TreeNode *root, Data *d1, Data *d2) {
    static Data initData = {0, 0, 0};
    if (root == NULL) return &initData;
    Data *d = (Data *)malloc(sizeof(Data));
    d->dep = fmax(d1->dep, d2->dep) + 1;
    d->size = d1->size + d2->size + 1;
    d->depSize = (int *)malloc(sizeof(int) * d->dep);
    d->depSize[0] = 1;
    for (int i = 1; i < d->dep; i++) {
        #define SIZE(d, i) (i >= d->dep ? 0 : d->depSize[i])
        d->depSize[i] = SIZE(d1, i - 1) + SIZE(d2, i - 1);
        #undef SIZE
    }
    return d;
}

void clearData(Data *d) {
    if (d == NULL || d->dep == 0) return ;
    free(d->depSize);
    free(d);
    return ;
}

Data *getSizeAndDep(struct TreeNode *root) {
    if (root == NULL) return initData(root, NULL, NULL);
    Data *d1 = getSizeAndDep(root->left);
    Data *d2 = getSizeAndDep(root->right);
    Data *d = initData(root, d1, d2);
    clearData(d1);
    clearData(d2);
    return d;
}

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if (root == NULL) {
        *columnSizes = NULL;
        *returnSize = 0;
        return NULL;
    }
    Data *info = getSizeAndDep(root);
    int **ret = (int **)malloc(sizeof(int *) * info->dep);
    for (int i = 0; i < info->dep; i++) {
        ret[i] = (int *)malloc(sizeof(int) * info->depSize[i]);
    }
    int *data = (int *)malloc(sizeof(int) * info->size);
    struct TreeNode **q = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * info->size);   
    int head = 0, tail = 1;
    data[0] = root->val;
    q[0] = root;
    while (head < tail) {
        struct TreeNode *node = q[head++];
        if (node->left) {
            data[tail] = node->left->val;
            q[tail++] = node->left;
        }
        if (node->right) {
            data[tail] = node->right->val;
            q[tail++] = node->right;
        }
    }
    for (int i = 0, top = 0; i < info->dep; i++) {
        for (int j = 0; j < info->depSize[i]; j++, top++) {
            ret[i][j] = data[top];
        }
    }
    *returnSize = info->dep;
    *columnSizes = info->depSize;
    for (int i = 0; i < info->dep; i++) {
        for (int j = 0; j < info->depSize[i]; j++) {
            printf("%d ", ret[i][j]);
        }
        printf("\n");
    }
    free(data);
    free(info);
    return ret;
}

int main() {
    printf(".cpp\n");
    return 0;
}
