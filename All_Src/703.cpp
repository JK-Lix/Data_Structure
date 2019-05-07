/*************************************************************************
	> File Name: 703.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年
 ************************************************************************/

/*
 * Problem:
 *
 * Design a class to find the kth largest element in a stream. Note that 
 * it is the kth largest element in the sorted order, not the kth distinct
 * element.
 *
 * Your KthLargest class will have a constructor which accepts an integer
 * k and an integer array nums, which contains initial elements from the 
 * stream. For each call to the method KthLargest.add, return the element 
 * representing the kth largest element in the stream.
 *
 */


#include<stdio.h>
#include<stdlib.h>
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b, b = __temp;\
}

typedef struct {
    int* data;
    int n, size;
} KthLargest;

int kthLargestAdd(KthLargest *, int);

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->data = (int*)malloc(sizeof(int) * k + 1);
    obj->size = k;
    obj->n = 0;
    for (int i = 0; i < numsSize; i++) kthLargestAdd(obj, nums[i]);
    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->n < obj->size) {
        obj->data[++obj->n] = val;
        int ind = obj->n;
        while (ind != 1 && obj->data[ind] < obj->data[ind >> 1]) {
            swap(obj->data[ind], obj->data[ind >> 1]);
            ind >>= 1;
        }
    } else if (val > obj->data[1]) {
        obj->data[1] = val;
        int ind = 1;
        while (ind << 1 <= obj-> size) {
            int temp = ind, l = ind << 1, r = ind << 1 | 1;
            if (obj->data[l] < obj->data[temp]) temp = l;
            if (r <= obj->size && obj->data[r] < obj->data[temp]) temp = r;
            if (temp == ind) break;
            swap(obj->data[ind], obj->data[temp]);
            ind = temp;
        }
    }
    return obj->data[1];
}

void kthLargestFree(KthLargest* obj) {
    if (obj == NULL) return;
    free(obj->data);
    free(obj);
    return;
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);
 
 * kthLargestFree(obj);
*/

int main() {
    printf("703.cpp\n");
    return 0;
}
