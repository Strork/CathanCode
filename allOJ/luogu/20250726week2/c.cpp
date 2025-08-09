#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
int n, m;
queue<int> q;
int cnt[1000010];
pii e[4000010];
int lin[1000010];
int dep[1000010];
int len;

inline int insert(int x, int y) {
    e[++len] = {y, lin[x]};
    lin[x] = len;
}

void bfs() {
    cnt[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = lin[x]; i; i = e[i].second) {
            int y = e[i].first;
            if (!dep[y] || dep[y] == dep[x] + 1) { // 如果是下一层的点
                cnt[y] += cnt[x];
                cnt[y] %= 100003;
            }
        }
    }
    
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        insert(x, y);
        insert(y, x);
    }
    bfs();
    return 0;
}