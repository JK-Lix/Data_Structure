/*************************************************************************
	> File Name: 239.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年
 ************************************************************************/

/*
 * Problem:
 *
 * Given an array nums, there is a sliding window of size k which is 
 * moving from the very left of the array to the very right. 
 * You can only see the k numbers in the window. Each time the sliding 
 * window moves right by one position. Return the max sliding window.
 *
 */


#include<stdio.h>
#include<stdlib.h>

/*
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 *
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int n = (numsSize == 0 ? 0 : numsSize - k + 1);
    int *ret = (int*)malloc(sizeof(int) * n);
    int *q = (int*)malloc(sizeof(int) * numsSize);
    int head = 0, tail = 0;
    *returnSize = n;
    n = 0;
    for (int i =0; i < numsSize; i++) {
        while (tail - head && nums[i] > nums[q[tail - 1]]) --tail;
        q[tail++] = i;
        if (i - q[head] + 1 > k) head++;
        if (i + 1 >= k) ret[n++] = nums[q[head]];
    }
    free(q);
    return ret;
}

int main() {
    printf("239.cpp\n");
    return 0;
}
