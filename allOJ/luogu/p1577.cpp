#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[100005];

bool check(int x) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += a[i] / x;
    }
    return sum >= k;
}

int main() {
    cin >> n >> k;
    int l = 1, r = 0;
    for (int i = 1; i <= n; ++i) {
        double x;
        cin >> x;
        a[i] = x * 100;
        r = max(r, a[i]); // 存最长的绳子
    }
    int ans = 0;
    while (l <= r) { // 二分答案
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid + 1; // 搜索更大的答案
            ans = mid;
        } else r = mid - 1;
    }
    printf("%.2lf", ans / 100.0);
    return 0;
}