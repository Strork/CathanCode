#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], b[N];
int n;
struct node {
    int aid, bid, v;
    bool operator<(const node& x) const { return v > x.v; }
};

int main() {
    cin >> n;
    priority_queue<node> q;
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &b[i]);
        node t = node{i, 1, a[i] + b[1]};
        q.push(t);
    }
    for (int i = 1; i <= n; ++i) {
        auto t = q.top();
        printf("%d ", t.v);
        q.pop();
        t.bid++;
        t.v = a[t.aid] + b[t.bid];
        q.push(t);
    }
    return 0;
}