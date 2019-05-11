/*************************************************************************
	> File Name: 278.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年
 ************************************************************************/

/*
 * Problem:
 *
 * You are a product manager and currently leading a team to develop a
 * new product. Unfortunately, the latest version of your product fails 
 * the quality check. Since each version is developed based on the 
 * previous version, all the versions after a bad version are also bad.
 * Suppose you have n versions [1, 2, ..., n] and you want to find out 
 * the first bad one, which causes all the following ones to be bad.You 
 * are given an API bool isBadVersion(version) which will return whether
 * version is bad. Implement a function to find the first bad version. 
 * You should minimize the number of calls to the API.
 *
 */


#include<stdio.h>
#include<stdlib.h>

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    long long head = 1, tail = n, mid;
    while (head < tail) {
        mid = head + ((head + tail) >> 1);
        if (isBadVersion(mid)) tail = mid + 1;
        else head = mid + 1;
    }
    return head;
}

int main() {
    printf("278.cpp\n");
    return 0;
}
