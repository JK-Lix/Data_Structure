/*************************************************************************
	> File Name: 350.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年
 ************************************************************************/

/*
 * Problem:
 *
 * Given two arrays, write a function to compute their intersection.
 *
 * Example 1:
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2,2]
 * 
 * Example 2:
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [4,9]
 *
 * Note:
 * *Each element in the result should appear as many times as it shows in 
 *  both arrays.The 
 * *result can be in any order.
 *
 */


#include<stdio.h>
#include<stdlib.h>

typedef struct Data {
    int val, cnt;
} Data;

typedef struct HashTable {
    Data *data;
    int *flag;
    int size;
} HashTable;

HashTable *init(int n) {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->data = (Data *)malloc(sizeof(Data) * n);
    h->flag = (int *)calloc(sizeof(int), (n / 31 + 1));
    h->size = n;
    return h;
}

int hash(int val) {
    return val & 0x7fffffff;
}

int check(HashTable *h, int ind) {
    int x = ind / 31, y = ind % 31;
    return h->flag[x] & (1 << y);
}

void set(HashTable *h, int ind, int val) {
    int x = ind / 31, y = ind % 31;
    h->flag[x] |= (1 << y);
    h->data[ind].val = val;
    h->data[ind].cnt = 0;
    return ;
}

void insert(HashTable *h, int val) {
    int ind = hash(val) % h->size;
    int times = 1;
    while (check(h, ind) && h->data[ind].val != val) {
        ind += (times * times);
        ind %= h->size;
        times += 1;
    }
    if (check(h, ind)) return ;
    set(h, ind, val);
    return ;
}

int query(HashTable *h, int val) {
    int ind = hash(val) % h->size;
    int times = 1;
    while (check(h, ind) && h->data[ind].val != val) {
        ind += (times * times);
        ind %= h->size;
        times += 1;
    }
    if (check(h, ind)) return ind;
    return -1;
}

int add_once(HashTable *h, int val, int delta) {
    int ind = query(h, val);
    if (ind == -1) return -1;
    h->data[ind].cnt += delta;
    return h->data[ind].cnt;
}

void clear(HashTable *h) {
    if (h == NULL) return ;
    free(h->data);
    free(h->flag);
    free(h);
    return ;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    HashTable *h = init(3 * nums1Size + 1);
    for (int i = 0; i < nums1Size; i++) {
        insert(h, nums1[i]);
    }
    for (int i = 0; i < nums1Size; i++) {
        add_once(h, nums1[i], 1);
    }
    int cnt = 0;
    int *ret = (int *)malloc(sizeof(int) * (nums1Size + 1));
    for (int i = 0; i < nums2Size; i++) {
        if (add_once(h, nums2[i], -1) >= 0) {
            ret[cnt++] = nums2[i];
        }
    }
    returnSize[0] = cnt;
    return ret;
}

int main() {
    printf("350.cpp\n");
    return 0;
}
