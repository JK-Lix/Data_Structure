/*************************************************************************
	> File Name: .cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年
 ************************************************************************/

/*
 * Problem:
 *
 * Given a n x n matrix where each of the rows and columns are sorted in 
 * ascending order, find the kth smallest element in the matrix.
 *
 * Note that it is the kth smallest element in the sorted order, not the
 * kth distinct element.
 *
 */


#include<stdio.h>
#include<stdlib.h>

typedef struct Data {
    int cnt, rank;
} Data;

Data count(int **matrix, int n, int m, int x) {
    int i = n, j = 0, rank = 0, cnt = 0, k;
    for (int j = 0; j < m; j++) {
        while (i > 0 && matrix[i - 1][j] > x) --i;
        rank += i;
        k = i - 1;
        while (k >= 0 && matrix[k][j] == x) --k, ++cnt;
    }
    Data d = {cnt, rank};
    return d;
}

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k){
    int n = matrixSize, m = matrixSize;
    int head = matrix[0][0], tail = matrix[n - 1][n - 1], mid;
    while (head <= tail) {
        mid = head + ((tail - head) >> 1);
        Data d = count(matrix, n, m, mid);
        if (k <= d.rank && k >= d.rank - d.cnt + 1) {
            return mid;
        }
        if (d.rank < k) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

int main() {
    printf(".cpp\n");
    return 0;
}
