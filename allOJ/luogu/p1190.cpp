    #include <bits/stdc++.h>
    using namespace std;
    int n, m;
    int need[10005];
    int ans;
    priority_queue<int, vector<int>, greater<int>> q;

    int main() {
        cin >> n >> m;
        int i;
        for (i = 1; i <= m; ++i) {
            cin >> need[i];
            q.push(need[i]);
            ans = max(ans, need[i]);
        }
        while (i++ <= n) {
            cin >> need[i];
            int t = q.top();
            q.pop();
            q.push(t + need[i]);
            ans = max(ans, t + need[i]);
        }
        cout << ans << endl;
        return 0;
    }