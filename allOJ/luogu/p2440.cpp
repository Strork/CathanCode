#include <bits/stdc++.h>
using namespace std;
int n, k;
int wood[100005];

bool check(int x) { // 判断长度 x 是否能切出 k 段木头
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += wood[i] / x;
    }
    return sum >= k;
}

int main() {
    cin >> n >> k;
    int l = 1, r = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> wood[i];
        r = max(r, wood[i]);
    }
    int ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    cout << ans << endl;
    return 0;
}