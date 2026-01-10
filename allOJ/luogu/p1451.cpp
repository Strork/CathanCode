// #include <bits/stdc++.h>
// using namespace std;
// bool f[105][105];
// int dx[4] = {0,0,-1,1};
// int dy[4] = {1,-1,0,0};
// int n, m;
// int ans;
// struct node {
//     int x, y;
//     char ch;
// }a[105][105];

// void bfs(int x, int y) {
//     queue<node> q;
//     q.push(a[x][y]);
//     while (!q.empty()) {
//         node id = q.front();
//         q.pop();
//         f[id.x][id.y] = 1;
//         for (int i = 0; i < 4; ++i) {
//             int nx = id.x + dx[i];
//             int ny = id.y + dy[i];
//             if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
//             if (!f[nx][ny]) q.push(a[nx][ny]);
//         }
//     }
// }


// int main() {
//     cin >> n >> m;
//     for (int i = 1; i <= n; ++i) {
//         for (int j = 1; j <= m; ++j) {
//             cin >> a[i][j].ch;
//             if (a[i][j].ch == '0') f[i][j] = 1;
//             a[i][j].x = i;
//             a[i][j].y = j;
//         }
//     }
//     for (int i = 1; i <= n; ++i) {
//         for (int j = 1; j <= m; ++j) {
//             if (!f[i][j]) {
//                 bfs(i, j);
//                 ans++;
//             }
//         }
//     }
//     cout << ans;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
struct node {
    int x, y;
};
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
int n, m;
bool vis[105][105];

void bfs(node st) {
    queue<node> q;
    q.push(st);
    vis[st.x][st.y] = 1;
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = t.x + dx[i], ny = t.y + dy[i];
            if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
            if (vis[nx][ny]) continue; // 排除出界以及不合法点
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    } // 周围所有能去的点，都会被标记
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char c;
            cin >> c;
            if (c == '0') vis[i][j] = 1;
        }
    } // 先读取完毕，再进行处理，否则搜的不对
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!vis[i][j]) {
                bfs({i, j});
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}