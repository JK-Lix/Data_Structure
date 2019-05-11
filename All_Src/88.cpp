/*************************************************************************
	> File Name: 88.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年
 ************************************************************************/

/*
 * Problem:
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1
 * as one sorted array.
 *
 * Note:
 
 * *The number of elements initialized in nums1 and nums2 are m and n 
 *  respectively.
 * *You may assume that nums1 has enough space (size that is
 *  greater or equal to m + n) to hold additional elements from nums2.
 *
 */


#include<stdio.h>
#include<stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int p = m, q = n, t = m + n;
    while (p || q) {
        if (q == 0 || (p && nums1[p - 1] >= nums2[q - 1])) 
            nums1[--t] = nums1[--p];
        else nums1[--t] = nums2[--q];
    }
}

int main() {
    printf("88.cpp\n");
    return 0;
}
