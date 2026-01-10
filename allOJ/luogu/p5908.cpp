#include <bits/stdc++.h>
using namespace std;
struct node {
    int nt, y;
}e[200005];
int dis[100005];
int n, d, len, hd[100005], ans;

inline void insert(int x, int y) {
    e[++len] = {hd[x], y};
    hd[x] = len;
}

void dfs(int x) {
    for (int i = hd[x]; i; i = e[i].nt) {
        if (dis[e[i].y] == -1) {
            dis[e[i].y] = dis[x] + 1;
            if (dis[e[i].y] <= d) ans++;
            dfs(e[i].y);
        }
    }
}

int main() {
    cin >> n >> d;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        insert(x, y);
        insert(y, x);
    }
    memset(dis, -1, sizeof(dis));
    dis[1] = 0;
    dfs(1);
    cout << ans << endl;
    return 0;
}