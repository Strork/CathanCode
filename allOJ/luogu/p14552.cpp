#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool vis[N], col[N];
int cnt[2];
int n;
vector<int> e[N];

inline void insert(int x, int y) { e[x].push_back(y), e[y].push_back(x); }

void dfs(int x) {
    vis[x] = 1, ++cnt[col[x]];
    for (auto y : e[x]) {  // 这道题保证了二分图，不用判断
        if (!vis[y]) {
            col[y] = col[x] ^ 1;
            dfs(y);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        insert(x, y);
    }
    for (int i = 1; i <= n; ++i)
        if (!vis[i]) dfs(i);
    int k;
    cin >> k;
    int ddl = 0;
    if (cnt[0] >= k)
        for (int i = 1; i <= n; ++i) {
            if (col[i] == 0) {
                printf("%d ", i);
                ++ddl;
            }
            if (ddl == k) break;
        }
    else if (cnt[1] >= k)
        for (int i = 1; i <= n; ++i) {
            if (col[i] == 1) {
                printf("%d ", i);
                ++ddl;
            }
            if (ddl == k) break;
        }
    else
        cout << 0 << endl;
    return 0;
}