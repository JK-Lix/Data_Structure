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
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time 
 * complexity should be O(log (m+n)).
 *
 * You may assume nums1 and nums2 cannot be both empty.
 *
 */


#include<stdio.h>
#include<stdlib.h>

#define fmin(a, b) (a < b ? a : b)

double find(int *a, int *b, int n, int m, int k, int flag) {
    if (m == 0 && n == 0) return 0;
    if (n == 0 || m == 0) {
        if (m == 0) b = a;
        if (flag) return b[k - 1];
        return 1.0 * (b[k - 1] + b[k]) / 2.0;
    }
    if (k == 1) {
        int ret[2], t = 0;
        int p = 0, q = 0;
        while (p < n || q < m && t < 2) {
            if (q >= m || (p < n && a[p] <= b[q])) {
                ret[t++] = a[p++];
            } else {
                ret[t++] = b[q++];
            }
        }
        if (flag) return ret[0];
        return 1.0 * (ret[0] + ret[1]) / 2.0;
    }
    int ind_a = fmin(k >> 1, n);
    int ind_b = fmin(k - ind_a, m);
    ind_a = k - ind_b;
    if (ind_a > 0 && a[ind_a - 1] < b[ind_b - 1]) {
        return find(a + ind_a, b, n - ind_a, m, k, flag);
    }
    return find(a, b + ind_b, n, m - ind_b, k, flag);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int n = nums1Size + nums2Size;
    int k = (nums1Size + nums2Size + 1) >> 1;
    return find(nums1, nums2, nums1Size, nums2Size, k, n & 1);
}

int main() {
    printf(".cpp\n");
    return 0;
}
