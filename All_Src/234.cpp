/*************************************************************************
	> File Name: 234.cpp
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

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
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

int getListLength(struct ListNode *head) {
    int ret = 0;
    while (head) ++ret, head = head->next;
    return ret;
}

struct ListNode *getIndex(struct ListNode *head, int ind) {
    struct ListNode *p = head;
    while (ind--) p = p->next;
    return p;
}

bool isPalindrome(struct ListNode* head) {
    int n = getListLength(head);
    struct ListNode *p = getIndex(head, (n + 1) / 2);
    p = reverseList(p);
    while (head && p) {
        if (head->val - p->val) return false;
        head = head->next;
        p = p->next;
    }
    return true;
}

int main() {
    printf("234.cpp\n");
    return 0;
}
