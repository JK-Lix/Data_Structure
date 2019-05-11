/*************************************************************************
	> File Name: 374.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年
 ************************************************************************/

/*
 * Problem:
 *
 * We are playing the Guess Game. The game is as follows:I pick a number 
 * from 1 to n. You have to guess which number I picked.Every time you 
 * guess wrong, I'll tell you whether the number is higher or lower.
 *
 * You call a pre-defined API guess(int num) which returns 3 possible
 * results (-1, 1, or 0):
 *
 */


#include<stdio.h>
#include<stdlib.h>

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int head = 1, tail = n, mid;
        while (head <= tail) {
            mid = head + ((tail - head) >> 1);
            int ret = guess(mid);
            if (ret == 0) return mid;
            if (ret < 0) tail = mid - 1;
            else head = mid + 1;
        }
        return -1;
    }
};

int main() {
    printf("374.cpp\n");
    return 0;
}
