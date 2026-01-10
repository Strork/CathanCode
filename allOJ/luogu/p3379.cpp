#include <bits/stdc++.h>
using namespace std;
vector<int> a[500005];  // 存树
int fa[500005][26];     // 倍增数组，f[x][i] 表示节点 x 跳 2^i 到的点
int dep[500005];        // 深度
int n, m, root;

void dfs(int x, int fat) {
    // for (int i = 0; i < a[x].size(); ++i) { //遍历节点x的子节点
    for (auto y : a[x]) {
        if (y == fat) continue;  // 别遍历父节点
        dep[y] = dep[x] + 1;     // 记录 y 的深度
        fa[y][0] = x;            // 初始化，y 跳一格到 x
        for (int i = 1; i <= log2(dep[y]); ++i) {
            int jump = fa[y][i - 1];  // y 先跳 2^(i-1) 格
            fa[y][i] = fa[jump][i - 1];
        }
        dfs(y, x);  // 查找下一个节点
    }
}

int find(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);    // 保证 x 更深
    while (dep[x] > dep[y]) {           // 不是同一深度，向上跳
        int p = log2(dep[x] - dep[y]);  // 跳跃的距离是深度差
        x = fa[x][p];
    }
    if (x == y) return x;  // 发现 y 是 x 的祖先
    for (int p = log2(dep[x]); p >= 0; --p) {
        if (fa[x][p] != fa[y][p]) {      // 假如跳之后，还没碰到一起
            x = fa[x][p], y = fa[y][p];  // 本质是二进制拆分
        }
    }
    return fa[x][0];
}

int main() {
    cin >> n >> m >> root;
    for (int i = 1; i < n; ++i) {  // 读取N-1条边
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);  // 记录无向边的过程
        a[y].push_back(x);
    }
    fa[root][0] = 0;
    dfs(root, -1);
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        cout << find(x, y) << endl;
    }
    return 0;
}

void dfs(int x, int father) {
    for (auto y : a[x]) {
        if (y == father) continue;
        dep[y] = dep[x] + 1;
        fa[y][0] = x;
        for (int i = 1; i <= log2(dep[y]); i++) {
            int anc = fa[y][i - 1];
            fa[y][i] = fa[anc][i - 1];
        }
        dfs(y, x);
    }
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    while (dep[x] > dep[y]) {
        int p = log2(dep[x] - dep[y]);
        x = fa[x][p];
    }
    if (x == y) return x;
    for (int p = log2(dep[x]); p >= 0; --p)
        if (fa[x][p] != fa[y][p]) x = fa[x][p], y = fa[y][p];
    return fa[x][0];
}