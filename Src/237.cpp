/*************************************************************************
	> File Name: 237.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年
 ************************************************************************/

/*
 * Problem:
 *
 * Write a function to delete a node (except the tail) in a singly linked
 * list, given only access to that node.
 *
 */

// Tips: 广义删除即为数据覆盖

#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void deleteNode(struct ListNode* head) {
    struct ListNode *p = node->next;
    nod->val = node->next->val;
    node->next = node->next->next;
    free(p);
    return;
}

int main() {
    printf("237.cpp\n");
    return 0;
}
