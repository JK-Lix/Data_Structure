/*************************************************************************
	> File Name: cmp.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年05月12日 星期日 14时39分02秒
 ************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Test(func, a, b) { \
    printf("algorithm : %s = %d\n", #func, func(a, b)); \
}

int brute_force(const char *text, const char *pattern) {
    for (int i = 0; text[i]; i++) {
        int j;
        for (j = 0; pattern[j]; j++) {
            if (text[i + j] != pattern[j]) break;
        }
        if (pattern[j] == 0) return i;
    }
    return -1;
}

int kmp(const char *text, const char *pattern) {
    int len = strlen(pattern);
    int *next = (int *)malloc(sizeof(int) * len);
    next[0] = -1;
    int i, j = next[0];
    for (i = 1; pattern[i]; i++) {
        while (j != -1 && pattern[j + 1] != pattern[i]) j = next[j];
        if (pattern[j + 1] == pattern[i]) j += 1; 
        next[i] = j;
    }
    i = 0, j = -1;
    while (text[i]) {
        while (j != -1 && text[i] != pattern[j + 1]) j = next[j];
        if (text[i] == pattern[j + 1]) j += 1;
        if (pattern[j + 1] == 0) return i - len + 1;
        i += 1;
    }
    return -1;
}

int sunday(const char *text, const char *pattern) {
    int ind[128];
    int len1 = strlen(pattern);
    int len2 = strlen(text);
    for (int i = 0; i < 128; i++) {
        ind[i] = len1 + 1;
    }
    for (int i = 0; pattern[i]; i++) {
        ind[pattern[i]] = len1 - i;
    }
    for (int i = 0; i + len1 <= len2;) {
        int j = 0;
        for (j = 0; j < len1; j++) {
            if (text[i + j] != pattern[j]) {
                i += ind[text[i + len1]];
                break;
            }
        }
        if (j == len1) return i;
    }
    return -1;
}

int shift_and(const char *text, const char *pattern) {
    int code[128] = {0};
    int len = 0;
    for (int i = 0; pattern[i]; i++, len++) {
        code[pattern[i]] |= (1 << i);
    }
    int p = 0;
    for (int i = 0; text[i]; i++) {
        p = (p << 1 | 1) & code[text[i]];
        if (p & (1 << (len - 1))) return i - len + 1;
    }
    return -1;
}

int shift_or(const char *text, const char *pattern) {
    int code[128] = {0};
    memset(code, -1, sizeof(code));
    int len = 0;
    for (int i = 0; pattern[i]; i++, len++) {
        code[pattern[i]] &= ~(1 << i);
    }
    int p = -1;
    for (int i = 0; text[i]; i++) {
        p = (p << 1) | code[text[i]];
        if (~p & (1 << (len - 1))) return i - len + 1;
    }
    return -1;
}


int main() {
    char str1[1000], str2[1000]; 
    while (~scanf("%s%s", str1, str2)) {
        Test(brute_force, str1, str2);
        Test(kmp, str1, str2);
        Test(sunday, str1, str2);
        Test(shift_and, str1, str2);
        Test(shift_or, str1, str2);
    }
    return 0;
}

