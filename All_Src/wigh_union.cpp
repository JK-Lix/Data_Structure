/*************************************************************************
	> File Name: quick_find.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年05月21日 星期二 18时27分49秒
 ************************************************************************/

//并查集查找速度块
//适用于染色问题
//路径压缩+按质合并
#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) {\
                   __typeof(a) __temp = a;\
                    a = b, b = __temp;\
                   }

typedef struct UnionSet {
    int *fa, *size;
    int n;
} UnionSet;

UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->fa = (int *)malloc(sizeof(int) * (n + 1));
    u->size = (int *)malloc(sizeof(int) * (n + 1));
    u->n = n;
    for (int i = 1; i <= n; i++) {
        u->fa[i] = i;
        u->size[i] = 1;
    }
    return u;
}

//find操作
int find(UnionSet *u, int x) {
    return u->fa[x] = (u->fa[x] == x ? x : find(u, u->fa[x]));
}

//合并
int merge(UnionSet *u, int a, int b) {
    int fa = find(u, a), fb = find(u, b);
    if (fa == fb) return 0;
    //if (u->size[fa] > u->size[fb]) swap(fa, fb);  按质优化
    u->fa[fa] = fb;
    //u->size[fb] += u->size[fa];
    return 1;
}

void clear(UnionSet *u) {
    if (u == NULL) return;
    free(u->fa);
    free(u->size);
    free(u);
    return;
}

int main() {
    int n, m;
    int a, b, c;
    scanf("%d%d", &n, &m);
    UnionSet *u = init(n);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        switch(a) {
            case 1: merge(u, b, c); break;
            case 2: printf("%s\n", find(u, b) == find(u, c) ? "Yes" : "No"); break;
        }
    }
    clear(u);
    return 0;
}

