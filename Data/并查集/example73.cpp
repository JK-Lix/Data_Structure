/*************************************************************************
	> File Name: example72.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年05月21日 星期二 20时34分02秒
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<climits>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;

#define MAX_N 1000
#define MAX_M 1000

struct UnionSet {
    int fa[MAX_N + 5], n;
    void init(int n) {
        for (int i = 1; i <= n; i++) fa[i] = i;
    }
    int get(int x) {
        return fa[x] = (fa[x] == x ? x : get(fa[x]));
    }
    void merge(int a, int b) {
        fa[get(a)] = get(b);
    }
};

UnionSet u;
int n, m;
int ind(int i, int j) {
    return i * m + j + 1;
}

char g[MAX_N + 5][MAX_M + 5];

int main() {
    cin >> n >> m;
    u.init(n * m);
    for (int i = 0; i < n; i++) cin >> g[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] != 'O') continue;
            if (i && g[i - 1][j] == 'O') u.merge(ind(i, j), ind(i - 1, j));
            if (j && g[i][j - 1] == 'O') u.merge(ind(i, j), ind(i, j - 1));
            if (i == 0 || j == n - 1) u.merge(ind(i, j), 0);
            if (j == 0 || j == m - 1) u.merge(ind(i, j), 0);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] != 'O') continue;
            ans += (u.get(ind(i, j)) != u.get(0));
        }
    }
    cout << ans << endl;
    return 0;
}
