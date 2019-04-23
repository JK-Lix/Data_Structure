/*************************************************************************
	> File Name: 84.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年
 ************************************************************************/

/*
 * Problem:
 *
 * Given n non-negative integers representing the histogram's bar height
 * where the width of each bar is 1, find the area of largest rectangle
 * in the histogram.
 * 
 * --image: 84-1.png
 * Above is a histogram where width of each bar is 1, 
 * given height = [2,1,5,6,2,3].
 * 
 * --Image: 84-2.png
 * The largest rectangle is shown in the shaded area, 
 * which has area = 10 unit.
 *
 */


#include<stdio.h>
#include<stdlib.h>

int fmax(int a, int b) {
    return (a > b ? a : b);
}

int largestRectangleArea(int* heights, int heightsSize) {
    int top = -1;
    int *stack = (int *)malloc(sizeof(int) * heightsSize); 
    int *left = (int *)malloc(sizeof(int) * heightsSize); 
    int *right = (int *)malloc(sizeof(int) * heightsSize);
    for (int i = 0; i < heightsSize; i++) {
        while (top != -1 && heights[stack[top]] >= heights[i]) --top;
        left[i] = (top == -1 ? i + 1 : i - stack[top]);
        stack[++top] = i;
    }
    top = -1;//栈清空，覆盖写入即可
    for (int i = heightsSize - 1; i >= 0; i--) {
        while (top != -1 && heights[stack[top]] >= heights[i]) --top;
        right[i] = (top == -1 ? heightsSize - i : stack[top] - i);
        stack[++top] = i;
    }
    int ans = 0;
    for (int i = 0; i < heightsSize; i++) {
        ans = fmax(ans, (left[i] + right[i] - 1) * heights[i]);
    }
    free(stack);
    free(left);
    free(right);
    return ans;
}

int main() {
    printf("84.cpp\n");
    return 0;
}
