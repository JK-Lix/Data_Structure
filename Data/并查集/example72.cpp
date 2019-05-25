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

#define MAX_N 10000

//带权值并查集


struct UnionSet {
    int fa[MAX_N + 5], val[MAX_N + 5];
    void init(int n) {
        for (int i = 1; i <= n; i++) fa[i] = i, val[i] = 0;
    }
    int get(int x) {
        if (fa[x] == x) return x;
        int ret = get(fa[x]);
        val[x] += val[fa[x]];
        val[x] %= 3;
        return fa[x] = ret;
    }
    void merge(int a, int b, int c) {
        int aa = get(a), bb = get(b);
        if (aa == bb) return;
        fa[aa] = bb;
        val[aa] = (val[b] - val[a] + c + 3) % 3;
        return;
    }
};

int main() {
    int n, m;
    UnionSet u;
    cin >> n >> m;
    u.init(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) u.merge(b, c, 1);
        else {
            if (u.get(b) != u.get(c)) {
                cout << "Unknown" << endl;
                continue;
            }
            switch ((u.val[b] - u.val[c] + 3) % 3) {
                case 0: cout << "Tie" << endl; break;
                case 1: cout << "Win" << endl; break;
                case 2: cout << "Loss"<< endl; break;
            }
        }
    }
    return 0;
}
