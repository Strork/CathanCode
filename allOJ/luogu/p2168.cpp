#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node {
    ll v;
    ll dep;
    bool operator<(const node& y) const {
        if (v > y.v)
            return true;
        else if (v == y.v)
            return dep > y.dep;
        return false;
    }
};
ll n, k;
priority_queue<node> q;

int main() {
    // freopen("a.in", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        ll x;
        cin >> x;
        q.push({x, 0});
    }
    while ((q.size() - 1) % (k - 1) != 0) q.push({0, 0});
    // 每次选取 k 个最小的点，统计和
    ll ans = 0;
    while (q.size() >= k) {
        ll sum = 0;
        ll dep = 0;
        for (int i = 1; i <= k; ++i) {
            sum += q.top().v;             // 统计所有子节点的和
            dep = max(dep, q.top().dep);  // 最深的点
            q.pop();
        }
        ans += sum;  // 统计和
        q.push({sum, dep + 1});
    }
    printf("%lld\n%lld\n", ans, q.top().dep);
    return 0;
}