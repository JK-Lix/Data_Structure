/*************************************************************************
	> File Name: 221.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年
 ************************************************************************/

/*
 * Problem:
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest 
 * square containing only 1's and return its area.
 *
 */

// Tips: 简易单调队列维护区间最小值

#include <stdio.h>
#include <stdlib.h>

int fmax(int a, int b) {
    return (a > b ? a : b);
}

int maximalSquare(char** matrix, int matrixRowSize, int matrixColSizes) {
    int n = matrixRowSize;
    int m = matrixColSizes;
    if (n == 0) return 0;
    int **cnt = (int**)malloc(sizeof(int*) * n);
    int *q = (int*)malloc(sizeof(int) * m); 
    int head, tail, l;//初始化简易队列结构
    for (int i = 0; i < n; i++) cnt[i] = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) cnt[0][i] = (matrix[0][i] == '1');   
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cnt[n][m] = (matrix[i][j] == '1' ? cnt[i - 1][j] + 1 : 0);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        head = tail = 0;
        l = 0;
        for (int j = 0; j < m; j++) {
            while (tail - head > 0 && cnt[i][q[tail - 1]] > cnt[i][j]) --tail;
            q[tail++] = j;
            while (j - l >= 0 && j - l + 1 > cnt[i][q[head]]) {
                ++l;
                if (q[head] < l) ++head;
            }
            ans = fmax(ans, (j - l + 1) * (j - l + 1));
        }
    }
    for (int i = 0; i < n; i++) free(cnt[i]);
    free(cnt);
    free(q);
    return ans;
}

int main() {
    printf("221.cpp\n");
    return 0;
}
