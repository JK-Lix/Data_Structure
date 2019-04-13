/*************************************************************************
	> File Name: Queue.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年04月13日 星期六 20时43分43秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Queue {
    int *data;
    int head, tail, length, count;
} Queue;

Queue *init(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * n);
    q->length = n;
    q->count = 0;
    q->head = q->tail = 0;
    return q;
}

int front(Queue *q) {
    return q->data[q->head];
}

int empty(Queue *q) {
    return q->count == 0;
}

void push(Queue *q, int val) {
    if (q->count == q->length) return;
    q->data[(q->tail)++] = val;
    if (q->tail >= q->length) q->tail -= q->length;
    q->count += 1;
    return;
}

void pop(Queue *q) {
    q->head += 1;
    if (q->head >= q->length) q->head -= q->length;
    q->count -= 1;
    return;
}

void clear(Queue *q) {
    if (q == NULL) return;
    free(q->data);
    free(q);
    return;
}

void output(Queue *q) {
    printf("   [");
    for (int i  = 0; i < q->count; i++) {
        int ind = (q->head + i) % q->length;
        printf(" %d", q->data[ind]);
    }
    printf(" ]\n");
    return;
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    Queue *q = init(5);
    for (int i =0; i < MAX_OP; i++) {
        int op = rand() %2, val = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("insert %d to queue\n", val);
                push(q, val);
            } break;
            case 3: {
                printf("pop %d from queue\n", front(q));
                pop(q);
            }break;
        }
        output(q);
    }
    clear(q);
    return 0;
}

