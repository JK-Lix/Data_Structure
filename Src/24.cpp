/*************************************************************************
	> File Name: 24.c
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年04月11日 星期四 18时40分56秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

/*
 *p->next=q->nextq->next=p->next
  p->next->next=q
  p=q
 *q=q->next
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *p, *q, ret;
    ret.next = head;
    p = &ret;
    q = head;
    while (q && q->next) {
        p->next = q->next;
        q->next = p->next->next;
        p->next->next = q;
        p = q;
        q = q->next;
    }
    return ret.next;
}

int main() {
    printf("24.c\n");
    return 0;
}
