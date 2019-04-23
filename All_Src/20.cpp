/*************************************************************************
	> File Name: 20.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年
 ************************************************************************/

/*
 * Problem:
 *
 *
 *
 */


#include<stdio.h>
#include<stdlib.h>
#include<cstring>

bool isValid(char *s) {
    int len = strlen(s), top = -1, flag = 1;
    char *stack = (char*)malloc(sizeof(char) * len);
    while (s[0]) {
        switch(s[0]) {
            case '(' :
            case '[' :
            case '{' : stack[++top] = s[0]; break;
            case ')' : flag = (top != -1 && s[top--] == '('); break;
            case ']' : flag = (top != -1 && s[top--] == '['); break;
            case '}' : flag = (top != -1 && s[top--] == '{'); break;
        }
        if (!flag) break;
    }
    free(stack);
    return (flag && top == -1);
}

int main() {
    printf("20.cpp\n");
    return 0;
}
