/*************************************************************************
	> File Name: LinkList.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年04月09日 星期二 20时49分14秒
 ************************************************************************/

 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>

//节点定义
typedef struct LinkListNode {
    int data;
    struct LinkListNode *next;
} LinkListNode;

//链表定义
typedef struct LinkList {
    LinkListNode head;//虚拟头结点
    int length;
} LinkList;

LinkListNode *getNewNode (int val) {
    LinkListNode *p = (LinkListNode *)malloc(sizeof(LinkListNode));
    p->data = val;
    p->next = NULL;
    return p;
}

LinkList *getNewList() {
    LinkList *l = (LinkList *)malloc(sizeof(LinkList));
    l->head.next = NULL;
    l->length = 0;
    return l;
}

int insert(LinkList *l, int ind, int val) {
    if (ind < 0 || ind > l->length) return 0;
    LinkListNode *p = &(l->head), *new_node = getNewNode(val);
    while (ind--) p = p->next;
    new_node->next = p->next;
    p->next = new_node;
    l->length += 1;
    return 1;
}

int search(LinkList *l, int val) {
    int ind = 0;
    LinkListNode *p = l->head.next;
    while (p && p->data != val) p = p->next, ind += 1;
    if (ind == l->length) return -1;
    return ind;
}

void clear(LinkList *l) {
    LinkListNode *p = l->head.next, *q;
    while(p) {
        q = p;
        p = p->next;
        free(q);
    }
    free(l);
    return;
}

void output(LinkList *l) {
    printf("head ->");
    LinkListNode *p = l->head.next;
    while (p) {
        printf(" %d ->", p->data);
        p = p->next;
    }
    printf(" NULL\n");
    return;
}

void output_search(LinkList *l, int ind) {
    LinkListNode *p;
    int a = 2;
    while (a--) {
        int as = ind + 1;
        p = l->head.next;
        printf("   ");
        while (as-- && p) { 
            printf("     ");
            int sp = p->data / 10;
            if (!as) continue;
            while (as && sp) {
                sp /= 10;
                printf(" ");
            }
            p = p->next;
        }
        (a & 1) ? printf("^\n") : printf("|\n");
    }
}

 int main() {
    LinkList *l = getNewList();
    int ind, val;
    while (scanf("%d%d", &ind, &val) != EOF) {
        //等价于(~scanf("%d%d", &ind, &val))
        //EOF即为-1     即为1111111111
        printf("insert %d to linklist at %d = %d\n", val, ind, insert(l, ind, val));
        output(l);
        output_search(l, search(l, val));
    }
    return 0;
 }
