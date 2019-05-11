/*************************************************************************
	> File Name: 21.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年
 ************************************************************************/

/*
 * Problem:
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 *
 */


#include<stdio.h>
#include<stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode ret, *p, *q, *t;
    ret.next = NULL;
    t = &ret;
    p = l1, q = l2;
    while (p || q) {
        if (q == NULL || (p && p->val <= q->val)) {
            t->next = p;
            p = p->next;
            t = t->next;
        } else {
            t->next = q;
            q = q->next;
            t = t->next;
        }
    }
    return ret.next;
}

int main() {
    printf(".cpp\n");
    return 0;
}
