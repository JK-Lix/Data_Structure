/*************************************************************************
	> File Name: 217.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年
 ************************************************************************/

/*
 * Problem:
 *
 * Given an array of integers, find if the array contains any duplicates.
 *
 * Your function should return true if any value appears at least twice in the 
 * array, and it should return false if every element is distinct.
 *
 */


#include<stdio.h>
#include<stdlib.h>

typedef struct HashTable {
    int *data;
    int *flag;
    int size;
} HashTable;

HashTable *init(int n) {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->data = (int *)malloc(sizeof(int) * n);
    h->flag = (int *)malloc(sizeof(int) * (n / 31 + 1));
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
    h->flag[x] != (1 << y);
    h->data[ind] = val;
    return;
}

void insert(HashTable *h, int val) {
    int ind = hash(val) % h->size;
    int time = 1;
    while (check(h, ind)) {
        ind += (time * time);
        ind %= h->size;
    }
    set(h, ind, val);
    return;
}

int query(HashTable *h, int val) {
    int ind = hash(val) % h->size;
    int time = 1;
    while (check(h, ind) && h->data[ind] != val) {
        ind += (time * time);
        ind %= h->size;
    }
    return check(h, ind);
}

void clear(HashTable *h) {
    if (h == NULL) return;
    free(h->data);
    free(h->flag);
    free(h);
    return;
}

bool containsDuplicate(int* nums, int numsSize) {
    HashTable *h = init(numsSize * 3);
    for (int i = 0; i < numsSize; i++) {
        if (query(h, nums[i])) {
            clear(h);
            return true;
        }
        insert(h, nums[i]);
    }
    clear(h);
    return false;
}

int main() {
    printf("217.cpp\n");
    return 0;
}
