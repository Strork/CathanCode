#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
ll s, cnt[2000005], sum[2000005];
int w[2000005], v[2000005];
int qs[2000005][2];

ll check(int W) {
    for (int i = 1; i <= n; ++i) {
        cnt[i] = cnt[i - 1];
        sum[i] = sum[i - 1];
        if (w[i] >= W) { // cnt 1~i 符合条件的个数  sum 符合条件的价值和
            cnt[i]++;
            sum[i] += v[i];
        }
    }
    ll t = 0;
    for (int i = 1; i <= m; ++i) { // 统计所有区间的价值和
        int l = qs[i][0], r = qs[i][1];
        t += (cnt[r] - cnt[l - 1]) * (sum[r] - sum[l - 1]);
    }
    return t;
}

int main() {
    cin >> n >> m >> s;
    int l = 0, r = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i];
        r = max(r, w[i]); // 记录最重的矿石
    }
    for (int i = 1; i <= m; ++i) {
        cin >> qs[i][0] >> qs[i][1]; // 询问区间的起点终点
    }
    ++r; // 如果 W == r，将没有任何石头合格
    while (l <= r) {
        int mid = l + r >> 1;
        ll y = check(mid); // 设定 W = mid 时得到的 y 值（所有区间价值）
        if (y > s) l = mid + 1; // y > s，即石头价值太多，要向右变小
        else r = mid - 1;
    } // 停止循环时，y(l) 和 y(r) 是最接近 s 的两个数
    cout << min(abs(check(l) - s), abs(check(r) - s));
    return 0;
}