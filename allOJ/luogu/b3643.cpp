#include <bits/stdc++.h>
using namespace std;
bool a[1005][1005];
vector<int> b[1005];
int n, m;

void add(int x, int y, int w) {
    e[++len] = {y, head[x], w};
    head[x] = len;
}

for (int i = head[x]; i != -1; i = e[i].next) {
    int y = e[i].y, w = e[i].w;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        a[x][y] = a[y][x] = 1; // 邻接矩阵
        b[x].push_back(y); // 邻接表
        b[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) { // 输出邻接矩阵
        for (int j = 1; j <= n; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    for (int i = 1; i <= n; ++i) {
        cout << b[i].size() << ' ';
        sort(b[i].begin(), b[i].end()); // 邻接表排序输出
        for (auto j : b[i]) cout << j << ' ';
        cout << endl;
    }
    return 0;
}