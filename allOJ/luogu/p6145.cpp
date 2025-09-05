#include <bits/stdc++.h>
using namespace std;
int n, m, c;
int ve[100005], rd[100005], ts[100005], k;
struct edge { // 定义边的结构体
    int y, v;
};
vector<edge> e[100005];

void topSort() {
    stack<int> s;
    s.push(0);
    ts[++k] = 0;
    while (s.size()) {
        int x = s.top();
        s.pop();
        for (auto t : e[x]) {
            int y = t.y;
            --rd[y];
            if (!rd[y]) {
                s.push(y);
                ts[++k] = y;
            }
        }
    }
}

void get_ve() {
    memset(ve, 0, sizeof(ve));
    for (int i = 1; i <= k; ++i) {
        int x = ts[i];
        for (auto t : e[x]) {
            int y = t.y, v = t.v;
            ve[y] = max(ve[y], ve[x] + v);
        }
    }
}

int main() {
    cin >> n >> m >> c;
    for (int i = 1; i <= n; ++i) {
        int si;
        cin >> si;
        e[0].push_back({i, si});
        ++rd[i];
    }
    for (int i = 1; i <= c; ++i) {
        int a, b, x;
        cin >> a >> b >> x;
        e[a].push_back({b, x});
        ++rd[b];
    }
    topSort();
    get_ve();
    for (int i = 1; i <= n; ++i) cout << ve[i] << endl;
    return 0;
}