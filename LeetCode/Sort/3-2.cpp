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

int lengthOfLongestSubstring(char* s) {
    int ind[128], l = 0, ans = 0;
    memset(ind, -1, sizeof(ind));
    for (int i = 0; s[i]; i++) {
        l += 1;
        if (i - ind[s[i]] < l) l = i - ind[s[i]];
        ind[s[i]] = i;
        if (l > ans) ans = l;
    }
    return ans;
}

int main() {
    printf("3.cpp\n");
    return 0;
}
