#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node {
    int y, v, next;
}e[200005];
int head[100005], id;
int n;
ll dis[100005];
ll maxx;

inline void insert(int x, int y, int v) {
    e[++id] = {y, v, head[x]};
    head[x] = id;
}

void dfs(int x) {
    for (int i = head[x]; i; i = e[i].next) {
        int y = e[i].y, v = e[i].v;
        if (dis[y] == -1) {
            dis[y] = dis[x] + v;
            if (dis[y] > maxx) maxx = dis[y];
            dfs(y);
        }
    }
}

int main() {
    ll ans = 0;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y, v;
        cin >> x >> y >> v;
        insert(x, y, v);
        insert(y, x, v);
        ans += 2 * v;
    }
    memset(dis, -1, sizeof(dis));
    dis[1] = 0;
    dfs(1);
    cout << ans - maxx << endl;
    return 0;
}