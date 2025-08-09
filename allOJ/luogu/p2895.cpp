#include <bits/stdc++.h>
#define debug
using namespace std;
int n;
int danger[310][310];
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};

struct pii {
    int x, y, t=-1;
}a[310][310];

void pt() {
    for (int i = 0; i <= 80; ++i) {
        for (int j = 0; j <= 80; ++j) {
            printf("(%4d, %4d) ", a[i][j].t, danger[i][j]);
        }
        cout << endl;
    }
}

void init() {
    cin >> n;
    for (int i = 0; i <= 304; ++i) {
        for (int j = 0; j <= 304; ++j) {
            danger[i][j] = 1006;
            a[i][j].x = i;
            a[i][j].y = j;
        }
    }
    for (int i = 1; i <= n; ++i) {
        int x, y, t;
        cin >> x >> y >> t;
        danger[x][y] = min(danger[x][y], t);
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || ny < 0) continue;
            danger[nx][ny] = min(danger[nx][ny], t); // 标记危险格子的时间
        }
    }
}

void bfs() {
    queue<pii> q;
    a[0][0].t = 0;
    q.push(a[0][0]);
    while (!q.empty()) {
        pii now = q.front();
        q.pop();
        for (int i = 0; i <= 3; ++i) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            if (nx >= 302 || ny >= 302 || nx < 0 || ny < 0) continue;
            if (danger[nx][ny] > now.t + 1 && (a[nx][ny].t > now.t + 1 || a[nx][ny].t == -1)) { // 陨石降落之前能走
                a[nx][ny].t = a[now.x][now.y].t + 1;
                q.push(a[nx][ny]);
            }
        }
    }
    int ans = 1005;
    for (int i = 0; i <= 303; ++i) {
        for (int j = 0; j <= 303; ++j) {
            if (a[i][j].t >= 0 && a[i][j].t < ans && danger[i][j] > 1000) {
                ans = min(ans, a[i][j].t);
            }
        }
    }
    if (ans == 1005) cout << -1 << endl;
    else cout << ans << endl;
}

int main() {
    // freopen("a.out", "w", stdout);
    init();
    bfs();
    // pt();
    return 0;
}