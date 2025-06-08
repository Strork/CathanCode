#include <bits/stdc++.h>
using namespace std;
struct S{
    int x, y;
    int v;
}a[105][105];
int ans = 0;
int n;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int main() {
    cin >> n;
    queue<S> q;
    int cnt[2] = {0, 0};
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j].v;
            ++cnt[a[i][j].v];
            a[i][j].x = i;
            a[i][j].y = j;
            if (a[i][j].v == 1) q.push(a[i][j]);
        }
    }
    if (cnt[1] == n*n || cnt[2] == n*n) {
        cout << -1 << endl;
        return 0;
    }
    while (!q.empty()) {
        S now = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int x = now.x + dx[i];
            int y = now.y + dy[i];
            if (x<=0 || y<=0 || x>n || y>n) continue;
            if (a[x][y].v == 0) {
                a[x][y].v = now.v + 1;
                ans = max(a[x][y].v, ans); 
                q.push(a[x][y]);
            }
        }
    }
    cout << ans-1 << endl;
    return 0;
}