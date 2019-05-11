/*************************************************************************
	> File Name: 3.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年
 ************************************************************************/

/*
 * Problem:
 *
 * Given a string, find the length of the longest substring without 
 * repeating characters.
 *
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int check(char *s, int n) {
    char cnt[128] = {0};
    int p = 0;
    for (int i = 0; i < n; i++) {
        cnt[s[i]]++;
        if (cnt[s[i]] == 1) p += 1;
    }
    if (p == n) return 1;
    for (int i = n; s[i]; i++) {
        cnt[s[i]] += 1;
        if (cnt[s[i]] == 1) p += 1;
        cnt[s[i - n]] -= 1;
        if (cnt[s[i - n]] == 0) p -= 1;
        if (p == n) return 1;
    }
    return 0;
}

int lengthOfLongestSubstring(char* s) {
    int head = 0, tail = strlen(s), mid;
    while (head < tail) {
        mid = (head + tail + 1) >> 1;
        if (check(s, mid) == 1) head = mid;
        else tail = mid - 1;
    }
    return head;
}

int main() {
    printf("3.cpp\n");
    return 0;
}
