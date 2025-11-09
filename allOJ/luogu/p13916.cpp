#include <bits/stdc++.h>
using namespace std;
int n, T, s;
int a[100005], b[100005];
int sum[100005]; // 广告持续时间

int check_st(int st, int i) {
    int ad = 0;
    if (st + s > T) return T;
    int ed = st + s;
    int id = lower_bound(b + 1, b + 1 + n, ed) - b; // 找到区间落点的 id
    if (id > i) ad += sum[id - 1] - sum[i - 1]; // 统计 id 前面的广告时间
    if (id != n + 1 && ed > a[id]) ad += ed - a[id]; // 特判落点 id 的广告时间
    return s - ad; // 返回错过的滑雪节时间
}

int check_ed(int ed, int i) {
    int ad = 0;
    if (ed - s < 0) return T;
    int st = ed - s;
    int id = lower_bound(b + 1, b + 1 + n, st) - b; // 找到区间左边落点的 id
    if (id < i) ad += sum[i] - sum[id]; // 统计一定会覆盖完的广告时间
    if (st > a[id]) ad += b[id] - st; // 假如落点在广告中间，加一半
    else ad += b[id] - a[id]; // 假如落点在广告左边，全加上
    return s - ad; // 返回错过的滑雪节时间
}

int main() {
    cin >> n >> T >> s;
    int ans = T;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
        sum[i] = sum[i - 1] + (b[i] - a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        int t = check_st(a[i], i);
        ans = min(ans, t);
        t = check_ed(b[i], i);
        ans = min(ans, t);
    }
    if (ans == T) ans = T - sum[n]; // 假如不能以任何端点作为区间，那么一定是所有广告包含在内
    cout << ans << endl;
    return 0;
}