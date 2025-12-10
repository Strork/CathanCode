#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int n, m;
// 定义变量完整

bool check(int x) { // x 是 和
    int cnt = 1, sum = 0; // sum 是前一段的和
    for (int i = 1; i <= n; ++i) {
        // 假如 sum + a[i] <= x -> sum += a[i]
        // 否则 cnt++, sum = a[i]
    }
}

int main() {
    cin >> n >> m;
    int l = 1;
    long long r = 0;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        l = max(a[i], l); // 最大的数
        r += a[i]; // 所有数的和
    }
    if (r > 1e9) r = 1e9;
    while (l <= r) {
        int mid = (l + r) / 2; // mid 就是当前长度
        if (check(mid)) { // 检查木材的个数够不够
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}