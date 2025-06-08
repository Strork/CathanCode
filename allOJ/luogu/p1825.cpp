#include <bits/stdc++.h>
using namespace std;
int n, m;
struct node{
    int x, y;
    int nx, ny;
    char ch;
    int dis;
}a[305][305];
int ht[130][2];
bool az[130];
bool vis[305][305];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
int sx, sy, fx, fy;

queue<node> q;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char ch;
            cin >> ch;
            a[i][j].ch = ch;
            if (ch == '@') sx = i, sy = j, vis[i][j] = 1;
            else if (ch == '#') vis[i][j] = 1;
            else if (ch == '=') fx = i, fy = j;
            else if (ch >= 'A' && ch <= 'Z') {
                if (!az[ch]) {
                    ht[ch][0] = i, ht[ch][1] = j;
                    az[ch] = 1;
                } else {
                    int x = ht[ch][0];
                    int y = ht[ch][1];
                    a[x][y].nx = i, a[x][y].ny = j;
                    a[i][j].nx = x, a[i][j].ny = y;
                }
            }
            a[i][j].x = i, a[i][j].y = j;
        }
    }
    q.push(a[sx][sy]);
    // 搜索操作
    bool find_end = 0;
    while (!q.empty()) {
        if (find_end) break;
        node now = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int x = now.x + dx[i];
            int y = now.y + dy[i];
            if (x == fx && y == fy) {
                find_end = 1;
                a[x][y].dis = now.dis + 1;
                break;
            }
            if (x <= 0 || y <= 0 || x > n || y > m) continue;
            if (!vis[x][y] && a[x][y].ch != '#') {
                int nx = x, ny = y; // nx ny 传送后的最终坐标
                if (a[x][y].nx) nx = a[x][y].nx, ny = a[x][y].ny;
                if (x == nx && y == ny) vis[x][y] = 1;
                a[nx][ny].dis = now.dis + 1;
                q.push(a[nx][ny]);
            }
        }
    }
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= m; ++j) {
    //         cout << vis[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << a[fx][fy].dis;
    return 0;
}