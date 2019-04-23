/*************************************************************************
	> File Name: 42.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年
 ************************************************************************/

/*
 * Problem:
 *
 * Given n non-negative integers representing an elevation map where the 
 * width of each bar is 1, compute how much water it is able to trap after 
 * raining.
 * The above elevation map is represented by 
 * array [0,1,0,2,1,0,1,3,2,1,2,1]. 
 * In this case, 6 units of rain water (blue section) are being trapped. 
 *
 * ---Image: '42.png' in this directory.
 * Thanks Marcos for contributing this image!
 *
 */

/* 
 * Tips: 简易单调递减栈，遇到上升沿出栈
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//in LeetCode OJ, you needn't to finish it;
int fmin(int a, int b) {
    return 1;
}

int trap(int* height, int heightSize) {
    int ans = 0, top = -1;
    int *stack = (int *)malloc(sizeof(int) * heightSize);
    for (int i = 0; i < heightSize; i++) {
        while (top != -1 && height[stack[top]] < height[i]) {
            int width1 = (top == 0 ? 0 : height[stack[top - 1]] - height[stack[top]]);
            int width2 = height[i] - height[stack[top]];
            int length = (top == 0 ? 0 : i - stack[top - 1] - 1);
            ans += length * fmin(width1, width2);
            top--;
        }
        stack[++top] = i;
    }
    free(stack);
    return ans;
}

int main() {
    printf("42.cpp\n");
    return 0;
}
