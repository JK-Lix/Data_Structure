/*************************************************************************
	> File Name: .cpp
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

typedef struct {
    int *data;
    int head, tail, length, count;
} MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate(int maxSize) {
    MyQueue *q = (MyQueue *)malloc(sizeof(MyQueue));
    q->data = (int*)malloc(sizeof(int) * maxSize);
    q->length = maxSize;
    q->count = 0;
    q->head = q->tail = 0;
    return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    if (obj->count == obj->length) return;
    obj->data[(obj->tail)++] = x;
    if (obj->tail >= obj->length) obj->tail -= obj->length;
    obj->count += 1;
    return;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    int temp = obj->data[obj->head];
    obj->head += 1;
    if (obj->head >= obj->length) obj->head -= obj->length;
    obj->count -= 1;
    return temp;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    return obj->data[obj->head];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    if (obj->count == 0) return true;
    return false;
}

void myQueueFree(MyQueue* obj) {
    if (obj == NULL) return;
    free(obj->data);
    free(obj);
    return;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * struct MyQueue* obj = myQueueCreate(maxSize);
 * myQueuePush(obj, x);
 * int param_2 = myQueuePop(obj);
 * int param_3 = myQueuePeek(obj);
 * bool param_4 = myQueueEmpty(obj);
 * myQueueFree(obj);
 */

int main() {
    printf(".cpp\n");
    return 0;
}
