// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;
// ll a[200005];
// int n, c;

// int find_first(int l, int r, int x) {
//     int t = r;
//     while (l <= r) {
//         int mid = l + r >> 1;
//         if (a[mid] < x) l = mid + 1;
//         if (a[mid] >= x) t = mid, r = mid - 1;
//     }
//     if (a[t] == x) return t;
//     return -1;
// }

// int find_last(int l, int r, int x) {
//     int t = l;
//     while (l <= r) {
//         int mid = l + r >> 1;
//         if (a[mid] <= x) t = mid, l = mid + 1;
//         if (a[mid] > x) r = mid - 1;
//     }
//     if (a[t] == x) return t;
//     return -1;
// }

// int main() {
//     cin >> n >> c;
//     ll ans = 0;
//     for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
//     sort(a + 1, a + 1 + n);
//     for (int i = 1; i <= n; ++i) {
//         int l = find_first(1, n, a[i] + c);
//         int r = find_last(1, n, a[i] + c);
//         if (l != -1) ans += r - l + 1; // 找到了再统计
//     }
//     cout << ans << endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int a[200005];
int ran[200005];
int cnt[200005];
int n, c;

int main() {
    cin >> n >> c;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n); // 排序
    ran[1] = 1;
    cnt[1]++;
    for (int i = 2; i <= n; ++i) { // 排名
        if (a[i] == a[i - 1]) ran[i] = ran[i - 1];
        else ran[i] = ran[i - 1] + 1;
        cnt[ran[i]]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int b = a[i] + c;
        int id = lower_bound(a + 1, a + 1 + n, b) - a;
        if (a[id] == b) ans += cnt[ran[id]];
    }
    cout << ans << endl;
    return 0;
}