
// 质因数分解定理：任何一个合数都可以由素数相乘得到
// 2 : 4... 标记为合数 8 12 16 18 20 27
// 3 : 6 9 、、、30
// 5 : 10 15 25、、、50
// 7 : 14 21 35 49
// 11:

#include <bits/stdc++.h>
using namespace std;
bool np[100005];
int p[100005];
int id = 0;

void pre() {
    // 欧拉筛 (线性筛)
    for (int i = 2; i <= 100000; ++i) {
        if (np[i] == 0) p[++id] = i;
        for (int j = 1; j <= id && p[j] * i <= 100000; ++j) { // j 是 质数数组的下标
            np[p[j] * i] = 1;
            if (i % p[j]) break; // 质数是 i 的因数, 停止
        }
    }
}

int main() {
    np[1] = 1;
    // 埃氏筛
    for (int i = 2; i <= 100000; ++i) { // 找 10 万以内的素数
        if (np[i] == 0) {
            id++;
            p[id] = i;
            for (int j = i * i; j <= 100000; j += i) np[j] = 1;
        }
    }
    
    return 0;
}