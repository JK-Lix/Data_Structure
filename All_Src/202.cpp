/*************************************************************************
	> File Name: 202.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年
 ************************************************************************/

/*
 * Problem:
 *
 * Write an algorithm to determine if a number is "happy".A happy number
 * is a number defined by the following process: Starting with any positive
 * integer, replace the number by the sum of the squares of its digits, 
 * and repeat the process until the number equals 1 (where it will stay), 
 * or it loops endlessly in a cycle which does not include 1. 
 * Those numbers for which this process ends in 1 are happy numbers.
 *
 */

// Tips:判断是否成环，追击问题

#include<stdio.h>
#include<stdlib.h>

int getNext(int x) {
    int ans = 0;
    while (x) {
        ans += (x % 10) * (x % 10);
        x /= 10;
    }
    return ans;
}

bool isHappy(int n) {
    int p = n, q = n;
    do {
        p = getNext(p);
        q = getNext(getNext(q));
    } while (p - q && q - 1);
    return q == 1;

}

int main() {
    printf("202.cpp\n");
    return 0;
}
