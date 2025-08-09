#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> a[1000010];
int s[1000010];
int depth[1000010];
ll f[1000010];
int n;
ll ans = 123456789ll;

void get_s(int x, int fa) {
    s[x] = 1;
    depth[x] = depth[fa] + 1;
    for (auto y : a[x]) {
        if (y == fa) continue;
        get_s(y, x);
        s[x] += s[y];
    }
}

void treedp(int x, int fa) {
    for (auto y : a[x]) {
        if (y == fa) continue;
        f[y] = f[x] + n - 2 * s[y];
        treedp(y, x);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    get_s(1, 1);
    for (int i = 1; i <= n; ++i) {
        f[1] += depth[i];
    }
    treedp(1, 1);
    int id = 0;
    for (int i = 1; i <= n; ++i) {
        if (f[i] < ans) {
            ans = f[i];
            id = i;
        }
    }
    cout << id << ' ' << ans << endl;
    return 0;
}