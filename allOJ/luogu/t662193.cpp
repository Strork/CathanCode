#include <bits/stdc++.h>
using namespace std;
int n, t, s;
int ads[100005];
int adc[100005];
int sum[100005];

int main() {
    cin >> n >> t >> s;
    for (int i = 1; i <= n; ++i) {
        cin >> ads[i] >> adc[i];
    }
    for (int i = 1; i <= n; ++i) { // 枚举每个广告
        if (ads[i] + s > t) break; // 不能从这个广告开始滑了
        int id = upper_bound(ads + 1, ads + 1 + n, ads[i] + s) - ads;
    }
    return 0;
}