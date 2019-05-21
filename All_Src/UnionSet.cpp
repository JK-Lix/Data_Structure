/*************************************************************************
	> File Name: quick_find.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年05月21日 星期二 18时27分49秒
 ************************************************************************/

//并查集查找速度块
//适用于染色问题

#include <stdio.h>
#include <stdlib.h>

typedef struct UnionSet {
    int *color;
    int n;
} UnionSet;

UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->color = (int *)malloc(sizeof(int) * (n + 1));
    u->n = n;
    for (int i = 1; i <= n; i++) {
        u->color[i] = i;
    }
    return u;
}

//find操作
int find(UnionSet *u, int x) {
    return u->color[x];
}

//合并
int merge(UnionSet *u, int a, int b) {
    if (find(u, a) == find(u, b)) return 0;
    int color_a = u->color[a];
    for (int i = 1; i <= u->n; i++) {
        if (u->color[i] - color_a) continue;
        u->color[i] = u->color[b];
    }
    return 1;
}

void clear(UnionSet *u) {
    if (u == NULL) return;
    free(u->color);
    free(u);
    return;
}

int main() {
    int n, m;
    int a, b, c;
    scanf("%d%d", &n, &m);
    UnionSet *u = init(n);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        switch(a) {
            case 1: merge(u, b, c); break;
            case 2: printf("%s\n", find(u, b) == find(u, c) ? "Yes" : "No"); break;
        }
    }
    clear(u);
    return 0;
}

