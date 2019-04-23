/*************************************************************************
	> File Name: 141.c
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年04月11日 星期四 18时58分37秒
 ************************************************************************/

/*
 * Problem:
 *
 * Given a linked list, determine if it has a cycle in it.
 * To represent a cycle in the given linked list, 
 * we use an integer pos which represents the position (0-indexed)
 * in the linked list where tail connects to. If pos is -1,
 * then there is no cycle in the linked list.
 *
 */

//Tips: 快慢指针，快指针与慢指针相遇则链表有环

#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode* head) {
    struct ListNode *p = head, *q = head;
    if (p == NULL) return false;
    do {
        p = p->next;
        q = q->next;
        if (q == NULL || q->next == NULL) return false; 
        q = q->next;
    } while (p != q);
    return true;
}

int main() {
    printf("141.c\n");
    return 0;
}
