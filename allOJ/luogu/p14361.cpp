#include <bits/stdc++.h>
using namespace std;
int n;
typedef pair<int, int> pii;
typedef long long ll;

int main() {
    int T; cin >> T; while (T--) {
        cin >> n;
        vector<int> club[4];
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            pii t[3];
            cin >> t[0].first >> t[1].first >> t[2].first;
            t[0].second = 1, t[1].second = 2, t[2].second = 3;
            sort(t, t + 3);
            // 最喜欢的俱乐部多一个人，并且记录这个人去其他俱乐部会少多少
            club[t[2].second].push_back(t[2].first - t[1].first);
            ans += t[2].first;
        }
        for (int i = 1; i <= 3; ++i) {
            if (club[i].size() > n / 2) {
                sort(club[i].begin(), club[i].end()); // 排序换人
                int m = club[i].size() - n / 2;
                for (int j = 0; j < m; ++j) ans -= club[i][j];
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}