/*************************************************************************
	> File Name: 160.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年
 ************************************************************************/

/*
 * Problem:
 *
 * Write a program to find the node at which the intersection of two 
 * singly linked lists begins.
 *
 */

//Tip:为了方便遍历，向短的链表添加多余节点，最后一个节点相同，判断链
//    表是否遍历到尾。     两个指针同时遍历两个链表，判断相同值

#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode *headB) {
    struct ListNode *p = headA, *q = headB;
    if (!p || !q) return NULL;    // 判断为空
    while (p->next != q->next) {
        p = (p ? p->next : headB);
        q = (q ? q->next : headA);
    }
    return p->next;
}

int main() {
    printf("160.cpp\n");
    return 0;
}
