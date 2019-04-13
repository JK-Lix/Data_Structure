/*************************************************************************
	> File Name: 83.c
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年04月11日 星期四 18时58分37秒
 ************************************************************************/


/* 
 * Problem:
 *
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 * 
 */



#include<stdio.h>
#include<stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *p = head;
    while (p && p->next) {
        if (p->val - p->next->val) {
            p = p->next;
        } else {
            q = p->next;
            p->next = q->next;
            free(q);
        }
    }
    return head;
}

int main() {
    printf("83.c\n");
    return 0;
}
