#include <bits/stdc++.h>
using namespace std;
vector<int> v[105], w[105];
vector<int> a;


int main() {
    int n, m;
    cin >> m >> n;
    for (int i = 1; i <= n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        v[c].push_back(a);
        w[c].push_back(b);
    }

    for (int i = 1; i <= 100; ++i) {// i表示组数
        for (int j = m; j >= 0; --j) { // j 还是容量
            for (int k = 0; k < v[i].size(); ++k) { // 枚举第 i 组 第 k 个物品
                if (j >= v[i][k]) {
                    f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
                }
            }
        }
    }

    return 0;
}