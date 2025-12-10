#include <bits/stdc++.h>
using namespace std;
int stp[25][25];
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2, 2, -2, -2, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1, 2, 2, -2, -2};
struct node {
	int x, y;
};

int main() {
    memset(stp, -1, sizeof(stp));
    stp[1][1] = 0;
    queue<node> q;
    q.push({1, 1});
    while (q.size()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 12; ++i) {
            int nx = t.x + dx[i], ny = t.y + dy[i];
            if (nx < 1 || ny < 1 || nx > 24 || ny > 24) continue;
            if (stp[nx][ny] != -1) continue;
            stp[nx][ny] = stp[t.x][t.y] + 1;
            q.push({nx, ny});
        }
    }
    int a, b;
    cin >> a >> b;
    cout << stp[a][b] << endl;
    cin >> a >> b;
    cout << stp[a][b] << endl;
    return 0;
}