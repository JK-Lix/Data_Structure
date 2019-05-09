/*************************************************************************
	> File Name: bubble_sort.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年05月07日 星期二 20时35分30秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define swap(a, b) { \
    a ^= b; b ^= a; a ^= b; \
}

#define TEST(arr, n, func, args...) { \
    int *num = (int *)malloc(sizeof(int) * n); \
    memcpy(num, arr, sizeof(int) * n); \
    output(num, n); \
    printf("%s = ", #func); \
    func(args); \
    output(num, n); \
    free(num); \
}

void bubble_sort(int *num, int n) {
    int times = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (num[j] <= num[j + 1]) continue;
                swap(num[j], num[j + 1]);
                times++;
        }
    }
    return ;
}

void randint(int *num, int n) {
    while (n--) num[n] = rand() % 100;
    return ;
}

void output(int *num, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf(" %d", num[i]);
    }
    printf("]\n");
    return ;
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    int arr[MAX_OP];
    randint(arr, MAX_OP);
    TEST(arr, MAX_OP, bubble_sort, num, MAX_OP);
    return 0;
}

