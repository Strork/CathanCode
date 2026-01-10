// #include <bits/stdc++.h>
// using namespace std;
// struct node {
//     int x, y;
// }st, ed;
// queue<node> q;
// int n;
// char a[1005][1005];
// int dis[1005][1005];
// int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};

// void bfs() {
//     q.push(st);
//     while (!q.empty()) {
//         node t = q.front();
//         q.pop();
//         for (int i = 0; i < 4; ++i) {
//             int nx = t.x + dx[i], ny = t.y + dy[i];
//             if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
//             if (dis[nx][ny] != -1 || a[nx][ny] == '1') continue;
//             dis[nx][ny] = dis[t.x][t.y] + 1;
//             if (nx == ed.x && ny == ed.y) return;
//             q.push({nx, ny});
//         }
//     }
// }

// int main() {
//     memset(dis, -1, sizeof(dis));
//     cin >> n;
//     for (int i = 1; i <= n; ++i) {
//         for (int j = 1; j <= n; ++j) {
//             cin >> a[i][j];
//         }
//     }
//     cin >> st.x >> st.y >> ed.x >> ed.y;
//     dis[st.x][st.y] = 0;
//     bfs();
//     cout << dis[ed.x][ed.y] << endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int n;
char a[1005][1005];
struct node{
    int x, y;
}st, ed;
int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};
int dis[1005][1005];

void bfs() {
    queue<node> q;
    q.push(st);
    while (!q.empty()) {
        node t = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = dx[i] + t.x, ny = t.y + dy[i];
            if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
            if (a[nx][ny] == '0' && dis[nx][ny] == 0) {
                q.push({nx, ny}); // dfs
                dis[nx][ny] = dis[t.x][t.y] + 1;
                // cout << nx << ' ' << ny << ' ' << dis[nx][ny] << endl;
                if (nx == ed.x && ny == ed.y) return;
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    cin >> st.x >> st.y >> ed.x >> ed.y;
    dis[st.x][st.y] = 1;
    bfs();
    cout << dis[ed.x][ed.y] - 1 << endl;
    return 0;
}