#include <bits/stdc++.h>
using namespace std;
int n, k;
struct edge {
    int y, to_edge;
    int val;
}e[2000010];
int head[1000005];
int fa[1000005];
int pre[1000005];
int d1[1000005], d2[1000005]; // 最长，次长
int dis1, dis2;
int pos;
int id;

inline void adde(int x, int y) {
    e[id].y = y; // 这条边的终点是谁
    e[id].to_edge = head[x]; // 这条边指向哪条边
    e[id].val = 1; // 边的权值
    head[x] = id; // 记录 x 的最新边的编号
    ++id;
}

void dfs(int x, int dep) { // dfs求直径
    if (dep >= dis1) {
        dis1 = dep;
        pos = x;
    }
    for (int i = head[x]; i != -1; i = e[i].to_edge) {
        int y = e[i].y;
        if (y == fa[x]) continue;
        fa[y] = x;
        pre[y] = i;
        dfs(y, dep+1);
    }
}

void changeEdge(int x) {
    if (fa[x]) {
        int t = pre[x];
        e[t].val = -1;
        e[t^1].val = -1;
        changeEdge(fa[x]);
    }
}

void treedp(int x, int father) {
    d1[x] = d2[x] = 0;
    for (int i = head[x]; i != -1; i = e[i].to_edge) {
        int y = e[i].y;
        if (y == father) continue;
        treedp(y, x);
        int t = d1[y] + e[i].val;
        if (t > d1[x]) {
            d2[x] = d1[x];
            d1[x] = t;
        }
        else if (t > d2[x]) d2[x] = t;
    }
    dis2 = max(dis2, d1[x] + d2[x]);
}

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        adde(x, y);
        adde(y, x);
    }
    dfs(1, 0); // 第一遍dfs，找pos
    memset(fa, 0, sizeof(fa));
    memset(pre, 0, sizeof(id));
    dfs(pos, 0); // 第二遍dfs，找直径
    if (k == 1) {
        cout << 2 * n - dis1 - 1;
        return 0;
    }
    changeEdge(pos);
    treedp(1, 0);
    cout << 2*n - dis1 - dis2 << endl;
    return 0;
}