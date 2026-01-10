#include <bits/stdc++.h>
using namespace std;
bool a[1005][1005];
vector<int> b[1005];
int n, m;
struct edge {
    int y, v, next;
}e[200005];
int len = 0;
int head[1005];

inline void addEdge(int x, int y) {
    // e[++len] = {y, v, head[x]};
    e[++len].y = y; // 把新边的数据存起来
    e[len].next = head[x]; // 头插法：将新的边指向 head[x] 
    head[x] = len;
}

void dfs(int x) {
    // for (auto y : a[x])
    for (int i = head[x]; i; i = e[i].next) {
        int y = e[i].y;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        a[x][y] = a[y][x] = 1; // 邻接矩阵

        b[x].push_back(y); // 邻接表
        b[y].push_back(x);

        addEdge(x, y);
        addEdge(y, x);
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
        // C++ 11 for (int i = 0; i < b[i].size(); ++i) 
        for (auto val : b[i]) cout << val << ' ';
        cout << endl;
    }
    dfs(1);
    return 0;
}