/*************************************************************************
	> File Name: 38.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年
 ************************************************************************/

/*
 * Problem:
 *
 * The count-and-say sequence is the sequence of integers with the first 
 * five terms as following:
 *
 * 1.     1
 * 2.     1
 * 3.     2
 * 4.     1211
 * 5.     111221
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 *
 * Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count
 * -and-say sequence.
 *
 *  Note: Each term of the sequence of integers will be represented as a 
 *  string.
 *
 */


#include<stdio.h>
#include<stdlib.h>

char * countAndSay(int n){
    if (n == 1) return strdup("1");
    char *s = countAndSay(n - 1);
    int len = 1;
    for (int i = 1; s[i]; i++) len += (s[i] != s[i - 1]);
    len = len << 1 + 1;
    char *ret = (char *)malloc(sizeof(char) * len);
    char ch = s[0];
    int cnt = 1, offset = 0;
    for (int i = 1; s[i]; i++) {
        if (s[i] == s[i - 1]) {
            cnt += 1;
        } else {
            offset += sprintf(ret + offset, "%d%c\0", cnt, ch);
            ch = s[i];
            cnt = 1;
        }
    }
    sprintf(ret + offset, "%d%c\0", cnt, ch);
    free(s);
    return ret;
}

int main() {
    printf("38.cpp\n");
    return 0;
}
