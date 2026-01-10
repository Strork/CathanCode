// #include <bits/stdc++.h>
// using namespace std;
// int n;
// vector<int> tree[200005];
// bool vis[200005];

// void dfs(int x, int fa) {
//     for (int i = 0; i < tree[x].size(); ++i) {
//         int y = tree[x][i];
//         if (y == fa) continue;
//         dfs(y, x);
//     }
// }

// int main() {
//     cin >> n;
//     for (int i = 1; i < n; ++i) {
//         int x, y;
//         cin >> x >> y;
//         tree[x].push_back(y);
//         tree[y].push_back(x);
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int n;
struct edge {
    int y, nt;
}e[1000000];
int head[200005], id;
int dis[200005];
int cnt[2];

inline void insert(int x, int y) {
    e[++id] = {y, head[x]};
    head[x] = id;
}

void bfs() {
    queue<int> q;
    dis[1] = 0;
    cnt[0]++;
    q.push(1);
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        for (int i = head[x]; i; i = e[i].nt) {
            int y = e[i].y;
            if (dis[y] != -1) continue;
            dis[y] = dis[x] + 1;
            cnt[dis[y] & 1]++;
            q.push(y);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        insert(x, y);
        insert(y, x);
    }
    memset(dis, -1, sizeof(dis));
    bfs();
    for (int i = 1; i <= n; ++i) {
        printf("%d ", cnt[dis[i] & 1]);
    }
    return 0;
}