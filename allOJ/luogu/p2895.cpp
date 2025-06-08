#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
queue<pii> q;
struct aw {
    int x, y, t;
}obs[50050];
int m;
int a[305][305];
int dx[8]={0,0,-1,1,-2,-1,1,2};
int dy[8]={-1,1,0,0,-1,-2,-2,-1};

bool mycmp (aw aa, aw bb) { return aa.t < bb.t; }

int main() {
    int m;
    cin >> m;
    memset(a, -1, sizeof(a));
    for (int i = 1; i <= m; ++i) {
        cin >> obs[i].x >> obs[i].y >> obs[i].t;
    }
    sort(a+1, a+1+m, mycmp);
    int tim = 0;
    int id = 1;
    for (; id <= m; ++id) {
        if (obs[id].t > tim) break;
        
    }
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