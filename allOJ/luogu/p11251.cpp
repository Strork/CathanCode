#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
const int N = 100005;
int n;
vector<int> a[N];
int col[N];
int dis[N];
bool f[N];
int ans = 0;


int bfs(int s) {
    queue<int> q;
    memset(f, 0, sizeof(f));
    q.push(s);
    f[s] = 1;
    pii maxx = make_pair(0,0);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto y : a[x]) {
            if (!f[y]) {
                f[y] = 1;
                dis[y] = dis[x] + 1;
                if (dis[y] > maxx.first) {
                    maxx.first = dis[y];
                    maxx.second = y;
                }
                q.push(y);
            }
        }
    }
    return maxx.second;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> col[i];
    }
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if (col[x] ^ col[y]) {
            a[x].push_back(y);
            a[y].push_back(x);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!f[i]) {
            int s = bfs(i);
            s = bfs(s);
            ans = max(ans, dis[s]);
        }
    }
    cout << ans+1 << endl;
    return 0;
}