#include <bits/stdc++.h>
using namespace std;
struct mp {
    int x, y;
    int dis;
}a[25][25];
int dx[] = {2,2,1,-1,-2,-2,-2,-2,-1,1,2,2};
int dy[] = {1,2,2,2,2,1,-1,-2,-2,-2,-2,-1};

int main() {
    for (int i = 1; i <= 22; ++i) {
        for (int j = 1; j <= 22; ++j) {
            a[i][j].x = i;
            a[i][j].y = j;
            a[i][j].dis = -1;
        }
    }
    a[1][1].dis = 0;
    queue<mp> q;
    q.push(a[1][1]);
    while (!q.empty()) {
        mp b = q.front();
        q.pop();
        for(int i = 0; i < 8; ++i) {
            int x = b.x + dx[i];
            int y = b.y + dy[i];
            if (x <= 0 || x >= 23 || y <= 0 || y >= 23) continue;
            if (a[x][y].dis == -1) {
                a[x][y].dis = b.dis + 1;
                q.push(a[x][y]);
            }
        }
    }
    int x, y;
    cin >> x >> y;
    cout << a[x][y].dis << endl;
    cin >> x >> y;
    cout << a[x][y].dis << endl;
    return 0;
}