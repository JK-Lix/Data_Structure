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
 * Median is the middle value in an ordered integer list. If the size of 
 * the list is even, there is no middle value. So the median is the mean 
 * of the two middle value.
 *
 * For example,
 * [2,3,4], the median is 3
 * [2,3], the median is (2 + 3) / 2 = 2.5
 *
 * Design a data structure that supports the following two operations:
 *      void addNum(int num) - Add a integer number from the data stream 
 *      to the data structure.
 *      
 *      double findMedian() - Return the median of all elements so far.
 *
 */


#include<stdio.h>
#include<stdlib.h>

typedef struct Heap {
    int *data;
    int n, size;
} Heap;

void expandHeap(Heap *h) {
    h->data = realloc(h->data, 2 * h->size * sizeof(int));
    h->size *= 2;
    return ;
}

#define swap(a, b) {\
        __typeof(a) __temp = a;\
        a = b, b = __temp;\
}

#define pushHeap(h, val, comp) {\
    if (h->size == h->n + 1) {\
        expandHeap(h);\
    }\
    h->data[++(h->n)] = val;\
    int ind = h->n;\
    while (ind != 1 && h->data[ind] comp h ->data[ind >> 1]) {\
        swap(h->data[ind], h->data[ind >> 1]);\
        ind >>= 1;\
    }\
}

#define popHeap(h, comp) do {\
    if (h->n == 0) break;\
    h->data[1] = h->data[(h->n)--];\
    int ind = 1;\
    while (ind << 1 <= h->n) {\
        int temp = ind, l = ind << 1, r = ind << 1 | 1;\
        if (h->data[l] comp h->data[temp]) temp = l;\
        if (r <= h->n && h->data[r] comp h->data[temp]) temp = r;\
        if (temp == ind) break;\
        swap(h->data[temp], h->data[ind]);\
        ind = temp;\
    }\
} while(0) //单纯为了使用break中断后续操作

Heap* createHeap() {
    Heap* h = (Heap*)malloc(sizeof(Heap));
    h->size = 100;
    h->data = (int*)malloc(sizeof(int) * h->size);
    h->n = 0;
    return h;
}

void clear(Heap* h) {
    if (h == NULL) return;
    free(h->data);
    free(h);
    return;
}

typedef struct {
    Heap* min_heap, *max_heap;
} MedianFinder;

/** initialize your data structure here. */

MedianFinder* medianFinderCreate() {
    MedianFinder* m = (MedianFinder*)malloc(sizeof(MedianFinder));
    m->min_heap = createHeap();
    m->max_heap = createHeap();
    return m;
}

void medianFinderAddNum(MedianFinder* m, int num) {
    if (m->min_heap->n == 0 || num >= m->min_heap->data[1]) {
        pushHeap(m->min_heap, num, <);
    } else {
        pushHeap(m->max_heap, num, >);
    }
    if (m->min_heap->n - m->max_heap->n == 2) {
        pushHeap(m->max_heap, m->min_heap->data[1], >);
        popHeap(m->min_heap, <);
    }
    if (m->max_heap->n - m->min_heap->n == 2) {
        pushHeap(m->min_heap, m->max_heap->data[1], <);
        popHeap(m->max_heap, >);
    }
    return;
}

double medianFinderFindMedian(MedianFinder* m) {
    switch (m->min_heap->n - m->max_heap->n) {
        case -1: return m->max_heap->data[1];
        case  0: return 1.0 * (m->min_heap->data[1] + m->max_heap->data[1]) / 2.0;
        case  1: return m->min_heap->data[1];
    }
}

void medianFinderFree(MedianFinder* m) {
    if (m == NULL) return;
    clear(m->min_heap);
    clear(m->max_heap);
    free(m);
    return;
}

/**
 * Your MedianFinder struct will be instantiated and called as such:
 * MedianFinder* obj = medianFinderCreate();
 * medianFinderAddNum(obj, num);
 
 * double param_2 = medianFinderFindMedian(obj);
 
 * medianFinderFree(obj);
*/

int main() {
    printf(".cpp\n");
    return 0;
}
