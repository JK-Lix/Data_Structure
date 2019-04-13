/*************************************************************************
	> File Name: test.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年04月13日 星期六 18时32分48秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<climits>
#include<cstdlib>
#include<math.h>
#include<string.h>
using namespace std;

#define MAX_M 100000  //边数
#define MAX_N 50000   //点数
#define MAX_K 19     //深度

struct Edge {
    int to, next;
} g[MAX_M + 5];  //存储第一条边在ｇ数组中的编号
//g[0] 不存储任何数据

int head[MAX_N + 5] = {0}, cnt = 0;    //head大小即为点数，ｇ为边数
//head[a]中存储第一条边的编号，即ｇ数组的下标
int gas[MAX_N + 5][MAX_K + 5] = {0}, deep[MAX_N + 5] = {0};

int father[MAX_N + 5] = {0};
int val[MAX_N + 5] = {0};

inline void add(int a, int b) {   //链式前向星添加边
    g[++cnt].to = b;   //这条边指向ｂ
    g[cnt].next = head[a]; //头插法
    head[a] = cnt; //存储当前这条边的编号
    return;
}

void dfs1(int fa, int ind) {
    father[ind] = fa;
    for (int i = 1; i <= MAX_K; i++) {
        gas[ind][i] = gas[gas[ind][i - 1]][i - 1];
    }
    for (int i = head[ind]; i; i = g[i].next) {
        if (g[i].to == fa) continue;
        int to = g[i].to;
        deep[to] = deep[ind] + 1;
        gas[to][0] = ind;
        dfs1(ind, to);
    }
    return ;
}

int lca(int x, int y) {
    if (deep[x] < deep[y]) swap(x, y);
    for (int i = MAX_K; i >= 0; i--) {
        if (deep[gas[x][i]] < deep[y]) continue;
        x = gas[x][i];
    }
    if (x == y) return x;
    for (int i = MAX_K; i >= 0; i--) {
        if (gas[x][i] == gas[y][i]) continue;
        x = gas[x][i], y = gas[y][i];
    }
    return gas[x][0];
}

int query(int ind) {
    int ans = 0;
    for (int i = head[ind]; i; i = g[i].next) {
        if (g[i].to == father[ind]) continue;
        ans += query(g[i].to);
    }
    ans += val[ind];
    return ans;
}

int main() {
    int n, m, s;
    std::ios::sync_with_stdio(false);
    cin >> n >> m >> s;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    deep[0] = -1;
    dfs1(0, s);
    for (int i = 0; i < m; i++) {
        int a, b, c, d, temp;
        cin >> a;
        switch (a) {
            case 1: {
                cin >> b >> c >> d;
                val[b] += d;
                val[c] += d;
                temp = lca(b, c);
                val[temp] -= d;
                val[father[temp]] -= d;
            } break;
            case 2: {
                cin >> b;
                cout << query(b) << endl;
            } break;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << val[i] << " ";
    }
    cout << endl;
    return 0;
}
