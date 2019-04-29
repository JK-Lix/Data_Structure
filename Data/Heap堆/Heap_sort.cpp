/*************************************************************************
	> File Name: Heap_sort.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年04月27日 星期六 19时32分21秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000
#define swap(a, b) {\
                   __typeof(a) __temp = a;\
                    a = b, b = __temp;\
                   }




int num[MAX_N + 5], n;

void update_down(int *num, int ind, int n) {
    while (ind << 1 <= n) {
        int temp = ind, lchild = ind << 1, rchild = ind << 1 | 1;
        if (num[temp] < num[lchild]) temp = lchild;
        if (rchild < n && num[temp] < num[rchild]) temp = rchild;
        if (temp == ind) break;
        swap(num[temp], num[ind]);
        ind = temp;
    }
    return;
}

void heap_sort(int *num, int n) {
    num -= 1; //指针向前移动一位，直接访问num[1]相当于访问num[0]位置
    for (int i = 2; i <= n; i++) update_down(num, i, n);
    for (int i = n; i >= 2; i--) {
        swap(num[i], num[1]);
        update_down(num, i, n);
    }
    return;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", num + i);
    heap_sort(num, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
    return 0;
}
