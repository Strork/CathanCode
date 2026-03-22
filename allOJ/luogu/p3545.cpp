#include <bits/stdc++.h>
using namespace std;
const int N = 3e5;
int n, cnt, a[N], b[N];
typedef pair<int, int> pii;
typedef long long ll;
ll goods = 0;
priority_queue<pii> q;
bool f[N];
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 1; i <= n; ++i) {
        goods += a[i];
        if (goods >= b[i])
            goods -= b[i], f[i] = 1, q.push({b[i], i}), cnt++;
        else {
            if (q.empty()) continue;                    // 前面没有满足任何人
            int x = q.top().first, y = q.top().second;  // 最差的顾客
            if (b[i] < x) {
                goods += x, f[y] = 0, q.pop();               // 反悔
                goods -= b[i], f[i] = 1, q.push({b[i], i});  // 满足新需求
            }
        }
    }
    cout << cnt << endl;
    for (int i = 1; i <= n; ++i)
        if (f[i]) cout << i << ' ';
    return 0;
}