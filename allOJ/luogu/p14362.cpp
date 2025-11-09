#include <bits/stdc++.h>
#define debug(x) cout << x << endl;
using namespace std;
typedef long long ll;
struct road {
    int x, y, v;
}e[1000005];
int n, m, k; 
vector<int> city[11];
int fa[10005];
bool use[15];
ll ans = 1LL << 62;

bool cmp(road a, road b) { return a.v < b.v; }
int get_fa(int x) {
    if (x == fa[x]) return x;
    return fa[x] = get_fa(fa[x]);
}

ll kruskal() {
    ll sum = 0, town = 0;
    vector<road> e2;
    for (int i = 1; i <= k; ++i) {
        if (use[i]) {
            town++;
            sum += city[i][0]; // 初始花费：改造城镇
            for (int j = 1; j <= n; ++j) {
                e2.push_back({i + n, j, city[i][j]});
            }
        }
    }
    sort(e2.begin(), e2.end(), cmp); // 排序新加入的边
    int i = 1, j = 0, cnt = 0;
    while (i <= m && j < e2.size()) {
        if (e[i].v <= e2[j].v) { // 选择原来的边加入集合
            int x = get_fa(e[i].x);
            int y = get_fa(e[i].v);
            if (x == y) {
                i++;
                continue;
            }
            fa[x] = y;
            ++cnt;
            sum += e[i].v;
            if (cnt == n - 1 + town) break;
        } else {
            int x = get_fa(e[i].x);
            int y = get_fa(e[i].v);
            if (x == y) {
                j++;
                continue;
            }
            fa[x] = y;
            ++cnt;
            sum += e2[j].v;
            if (cnt == n - 1 + town) break;
            ++j;
        }
    }
    if (cnt == n - 1 + town) return sum;
    while (i <= m) {
        int x = get_fa(e[i].x);
        int y = get_fa(e[i].v);
        if (x == y) {
            i++;
            continue;
        }
        fa[x] = y;
        ++cnt;
        sum += e[i].v;
        if (cnt == n - 1 + town) break;
        ++i;
    }
    if (cnt == n - 1 + town) return sum;
    while (j < e2.size()) {
        int x = get_fa(e[i].x);
        int y = get_fa(e[i].v);
        if (x == y) {
            j++;
            continue;
        }
        fa[x] = y;
        ++cnt;
        sum += e[i].v;
        if (cnt == n - 1 + town) break;
        ++j;
    }
    if (cnt == n - 1 + town) return sum;
    return sum;
}

void dfs(int x) {
    if (x >= k + 1) { // 抉择了 k 个新城镇之后
        debug(x);
        for (int i = 1; i <= n + k; ++i) fa[i] = i;
        ll t = kruskal();
        ans = min(t, ans);
        return;
    }
    use[x] = 1;
    dfs(x + 1);
    use[x] = 0;
    dfs(x + 1);
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= m; ++i) {
        scanf("%d %d %d", &e[i].x, &e[i].y, &e[i].v);
    }
    sort(e + 1, e + 1 + m, cmp);
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j <= n; ++j) {
            int v; scanf("%d", &v);
            city[i].push_back(v);
        }
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}