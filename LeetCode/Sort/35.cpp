/*************************************************************************
	> File Name: 35.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年
 ************************************************************************/

/*
 * Problem:
 *
 * Given a sorted array and a target value, return the index if the target
 * is found. If not, return the index where it would be if it were inserted
 * in order.
 *
 * You may assume no duplicates in the array.
 *
 */


#include<stdio.h>
#include<stdlib.h>

int searchInsert(int* nums, int numsSize, int target){
    int head = 0, tail = numsSize, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (nums[mid] >= target) tail = mid;
        else head = mid + 1;
    }
    return head;
}

int main() {
    printf("35.cpp\n");
    return 0;
}
