#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100005];

bool check(int x) {
    int sum = 0, cnt = 1;
    for (int i = 1; i <= n; ++i) {
        if (sum + a[i] <= x) sum += a[i];
        else {
            ++cnt;
            sum = a[i];
        }
    }
    return cnt <= m;
}

int main() {
    cin >> n >> m;
    int l = 0, r = 0; 
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] > l) l = a[i]; // L = 最大的数（至少单独成一段）
        r += a[i]; // R = 所有数的和（只有一段）
    }
    int ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}