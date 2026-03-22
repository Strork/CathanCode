#include <bits/stdc++.h>
using namespace std;
int n, ans;
typedef pair<int, int> pii;
pii cow[10005];
priority_queue<int, vector<int>, greater<int>> q;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> cow[i].second >> cow[i].first;
    sort(cow + 1, cow + 1 + n);
    for (int i = 1; i <= n; ++i) {
        if (q.size() < cow[i].first)
            q.push(cow[i].second), ans += cow[i].second;
        else {
            auto t = q.top();
            if (t < cow[i].second) {
                ans -= t, ans += cow[i].second;
                q.pop(), q.push(cow[i].second);
            }
        }
    }
    cout << ans << endl;
    return 0;
}