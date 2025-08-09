#include <bits/stdc++.h>
using namespace std;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
bool vis[15][15];
struct mp {
    int x, y, dis;
    int kd, hp;
}a[15][15];
int n, m;

int main() {
    cin >> n >> m;
    queue<mp> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j].kd;
            a[i][j].x = i, a[i][j].y = j;
            if (a[i][j].kd == 0) vis[i][j] = 1;
            if (a[i][j].kd == 2) {
                a[i][j].hp = 6;
                q.push(a[i][j]);
            }
        }
    }
    bool home = 0;
    while (!q.empty()) {
        if (home) break;
        mp now = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int x = now.x + dx[i], y = now.y + dy[i];
            if (x <= 0 || y <= 0 || x > n || y > m) continue;
            if (vis[x][y]) continue;
            int hp = now.hp - 1;
            if (hp == 0) continue; // 到下一格之前没血了
            if (a[x][y].kd == 4) {
                vis[x][y] = 1; // 加血的格子只会来一次
                hp = 6; // 先判断下一格子的情况
            }
            if (hp < a[x][y].hp) continue; 
            a[x][y].hp = hp;
            a[x][y].dis = now.dis + 1;
            if (a[x][y].kd == 3) {
                home = 1;
                cout << a[x][y].dis << endl;
                break;
            }
            q.push(a[x][y]);
        }
    }
    if (!home) cout << -1 << endl;
    return 0;
}