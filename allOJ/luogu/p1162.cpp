#include <bits/stdc++.h>
using namespace std;
struct qwq {
    int x, y;
};
queue<qwq> q;
int a[32][32];
bool vis[32][32];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    qwq st;
    st.x = st.y = 0;
    q.push(st);
    while (!q.empty()) {
        qwq id = q.front();
        q.pop();
        vis[id.x][id.y] = 1;
        for (int i = 0; i < 4; ++i) {
            int nx = id.x + dx[i], ny = id.y + dy[i];
            if (nx < 0 || ny < 0 || nx > n+1 || ny > n+1) continue;
            if (!vis[nx][ny] && !a[nx][ny]) {
                qwq tmp;
                tmp.x = nx, tmp.y = ny;
                q.push(tmp);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!vis[i][j] && !a[i][j]) cout << 2 << ' ';
            else cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}