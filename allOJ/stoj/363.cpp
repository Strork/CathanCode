#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
bool vis[N+5][N+5];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
struct xy {
    int x, y;
    int dis;
    char ch;
}a[N+5][N+5];
int n, m;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        queue<xy> q;
        xy Joe;
        memset(vis, 0, sizeof(vis)); // 初始化
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> a[i][j].ch;
                a[i][j].x = i;
                a[i][j].y = j;
                a[i][j].dis = -1;
                if (a[i][j].ch == '#') vis[i][j] = 1;
                if (a[i][j].ch == 'F') {
                    q.push(a[i][j]);
                    vis[i][j] = 1;
                }
                else if (a[i][j].ch == 'J') {
                    Joe.x = i;
                    Joe.y = j;
                    vis[i][j] = 1;
                    a[i][j].dis = 0;
                }
            }
        }
        q.push(a[Joe.x][Joe.y]);
        bool find_endpoint = 0;
        int ans = -1;
        while (!q.empty()) {
            if (find_endpoint) break;
            xy now = q.front();
            q.pop();
            if (now.ch == 'F') { // 如果当前队首是火，蔓延
                for (int i = 0; i < 4; ++i) {
                    int x = now.x + dx[i];
                    int y = now.y + dy[i];
                    if (vis[x][y]) continue;
                    if (a[x][y].ch == '.') {
                        vis[x][y] = 1;
                        a[x][y].ch = 'F';
                        q.push(a[x][y]);
                    }
                }
            }
            else if (now.ch == 'J') { // 如果当前队首是人，向四周走
                for (int i = 0; i < 4; ++i) {
                    int x = now.x + dx[i];
                    int y = now.y + dy[i]; // 下一个位置的坐标
                    if (x <= 0 || y <= 0 || x >= n+1 || y >= m+1) {
                        find_endpoint = 1;
                        // for (int i = 1; i <= n; ++i) {
                        //     for (int j = 1; j <= m; ++j)
                        //         cout << a[i][j].ch;
                        //     cout << endl;
                        // }
                        ans = now.dis + 1;
                        break;
                    }
                    if (vis[x][y]) continue;
                    if (a[x][y].ch == '.') {
                        vis[x][y] = 1;
                        a[x][y].ch = 'J';
                        a[x][y].dis = now.dis + 1;
                        q.push(a[x][y]);
                    }
                }
            }
        }
        if (ans == -1) cout << "IMPOSSIBLE" << endl;
        else cout << ans << endl;
    }
    return 0;
}