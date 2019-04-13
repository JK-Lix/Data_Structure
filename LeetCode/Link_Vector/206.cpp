/*************************************************************************
	> File Name: 206.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年
 ************************************************************************/

/*
 * Problem:
 *
 * Reverse a singly linked list.
 *
 */


#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head, int val) {
    struct ListNode *p, ret, *q;
    ret.next = NULL;
    p = head;
    while (p) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret.next;
}

int main() {
    printf("206.cpp\n");
    return 0;
}
