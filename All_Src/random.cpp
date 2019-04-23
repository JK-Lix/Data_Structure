/*************************************************************************
	> File Name: random.cpp
	> Author: Lix
	> Mail: 776579471@qq.com
	> URL: https://github.com/JK-Lix
	> Created Time: 2019年04月11日 星期四 20时47分52秒
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<climits>
#include<cstdlib>
#include<math.h>
#include<string.h>
#include <time.h>
using namespace std;

//自定义随机函数

static int seed = 1;

int my_srand(int s) {
    seed = ((s ^ (s < 7)* (s >> 5)) % 100 + 100) % 100 + 1; 
    return seed;
}

int my_random() {
    seed = (3 * seed) % 101;
    return seed;
}

int main() {
    my_srand(time(0));
    for (int i = 0; i < 100; i++) {
        cout << my_random() << endl;
    }
  /* 遍历系统随机函数的个数    图灵奖最高随机函数范围
   * int b = rand(), length = 0;
    while (b != rand()) length += 1;
    cout << length << endl;
    return 0;
  */
}
