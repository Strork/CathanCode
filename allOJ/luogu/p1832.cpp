#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool isp[1005];
int prime[1005];
int pid, n;
unsigned ll f[1005];
bool isPrime(int x) {
    if (x <= 1) return 0;
    if (x == 2) return 1;
    for (int i = 2; i*i <= x; ++i) {
        if (x%i == 0) return 0;
    }
    return 1;
}
void ola() { // 质数筛
    memset(isp, 1, sizeof(isp));
    isp[0] = isp[1] = 0;
    for (int i = 2; i <= 1000; ++i) {
        if (isp[i]) prime[++pid] = i; // 记录质数到数组中
        for (int j = 1; j <= pid && i * prime[j] <= 1000; ++j) {
            isp[i * prime[j]] = 0; // 用记录的质数标记合数
            if (i % prime[j] == 0) break; // 前面被标记过
        }
    }
}
int main() {
    cin >> n;
    ola();
    f[0] = 1;
    for (int i = 2; i <= n; ++i) { // 判断质数写法
        if(isPrime(i)) {
            for (int j = i; j <= n; ++j)
                f[j] += f[j - i];
        }
    }
    for (int i = 1; i <= pid; ++i) { // 筛法
        for (int j = prime[i]; j <= n; ++j) {
            f[j] += f[j - prime[i]];
        }
    }
    cout << f[n] << endl;
    return 0;
}
// f[0] = 1; 空集设定为一种方案
// for (int i = 2; i <= n; ++i) 
// 假如 i 是质数：
    // for (int j = i; j <= n; ++j) {
    //     f[j] += f[j - i];  把f[j-i]的方案数累加上来
    // }