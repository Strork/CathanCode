#include <bits/stdc++.h>
using namespace std;
int f[50100]; // 容积
int money[5010]; // 稻草
int important[50];
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int p;
        cin >> money[i] >> p;
        important[i] = money[i] * p;
    }
    for (int i = 1; i <= m; ++i) { // 遍历 m 个 物品
        for (int j = n; j >= money[i]; --j) {
                f[j] = max(f[j], f[j-money[i]] + important[i]);
        }
    }
    cout << f[n] << endl;
    return 0;
}