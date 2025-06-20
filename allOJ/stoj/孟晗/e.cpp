#include <bits/stdc++.h>
using namespace std;
int n;
int cnt[100100];
int depth[100100];
struct node {
    int y, nt;
}e[410000];
int lin[200100];
int len = 0;

inline void addE(int x, int y) {
    e[++len].y = y;
    e[len].nt = lin[x];
    lin[x] = len;
}

int dfs(int x, int fa, int dep) {
    bool f = 0;
    int t = 0;
    depth[x] = dep;
    for (int i = lin[x]; i; i = e[i].nt) {
        if (e[i].y == fa) continue;
        f = 1;
        t += dfs(e[i].y, x, dep+1);
    }
    if (!f) {
        cnt[x] = 1;
        return 1;
    }
    cnt[x] = t+1;
    return t+1;
}

void solution() {
    memset(cnt, 0, sizeof(cnt));
    memset(depth, 0, sizeof(depth));
    memset(e, 0, sizeof(e));
    memset(lin, 0, sizeof(lin));
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        addE(x, y);
        addE(y, x);
    }
    int t = dfs(1, 0, 1);
    for (int i = 1; i <= n; ++i) {
        printf("%d %d\n", depth[i], n - cnt[i] + 1);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solution();
    }
    return 0;
}