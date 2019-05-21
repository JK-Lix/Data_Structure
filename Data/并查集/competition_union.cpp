/*************************************************************************
	> File Name: competition_union.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年05月21日 星期二 20时03分10秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<climits>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;

#define MAX_N 10000

struct UnionSet {
    int fa[MAX_N + 5];
    void init(int n) {
        for (int i = 1; i <= n; i++) fa[i] = i;
    }
    int get(int x) {
        return fa[x] = (fa[x] == x ? x : get(fa[x]));
    }
    int merger(int a, int b) {
        fa[get(a)] = get(b);
    }
};

int main() {
    UnionSet u;
    int n, m;
    cin >> n >> m;
    u.init(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) u.merger(b, c);
        else cout << (u.get(c) == u.get(b) ? "Yes" : "No") << endl;
    }
    return 0;
}
