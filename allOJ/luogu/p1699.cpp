#include <bits/stdc++.h>
using namespace std;
int sx, sy, fx, fy;
bool vis[12][12];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

struct aa{
    int x, y;
    int dis;
    char ch;
}a[12][12];

int main() {
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            cin >> a[i][j].ch;
            if (a[i][j].ch == 'B') {
                fx = i;
                fy = j;
            } else if (a[i][j].ch == 'L') {
                sx = i;
                sy = j;
            } else if (a[i][j].ch == 'R') {
                vis[i][j] = 1;
            }
            a[i][j].x = i;
            a[i][j].y = j;
        }
    }
    queue<aa> q;
    vis[sx][sy] = 1;
    q.push(a[sx][sy]);
    bool find_end = 0;
    while (!q.empty()) {
        if (find_end) break;
        aa id = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int x = id.x + dx[i];
            int y = id.y + dy[i];
            if (x <= 0 || y <= 0 || x > 10 || y > 10) continue;
            if (x == fx && y == fy) {
                find_end = 1;
                a[x][y].dis = id.dis + 1;
                break;
            }
            if (!vis[x][y]) {
                vis[x][y] = 1;
                a[x][y].dis = id.dis + 1;
                q.push(a[x][y]);
            }
        }
    }
    cout << a[fx][fy].dis - 1 << endl;
    return 0;
}