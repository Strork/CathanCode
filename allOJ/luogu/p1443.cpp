#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
queue<pii> q;
int n, m, sx, sy;
int a[405][405];
int dx[8]={2,1,-1,-2,-2,-1,1,2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};

int main() {
    cin >> n >> m >> sx >> sy;
    q.emplace(sx, sy);
    memset(a, -1, sizeof(a));
    a[sx][sy] = 0;
    while (!q.empty()) {
        pii t = q.front();
        q.pop();
        for (int i = 0; i < 8; ++i) {
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];
            if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
            if (a[nx][ny] >= 0) continue;
            q.emplace(nx, ny);
            a[nx][ny] = a[t.first][t.second] + 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}