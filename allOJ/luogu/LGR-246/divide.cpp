#include <bits/stdc++.h>
#define ll long long
#define MOD 998244353
using namespace std;
int dep[1000005]; // 节点深度
int high[1000005]; // 节点高度
int level[1000005]; // 某层最低高度（作为序列起点）
int cnt[1000005]; // 深度节点数计数
int fact[1000005], infa[1000005]; // 阶乘与逆元
vector<int> a[1000005];
int n, k;

inline int read() {
    int read_num = 0, posibal = 1; char chh = 0;
    while (!isdigit(chh)) { if (chh=='-') posibal=-1;chh=getchar(); }
    while (isdigit(chh)) { read_num=read_num*10+(chh-'0');chh=getchar(); }
    return read_num * posibal;
}

inline ll fp(ll x, ll y) {
    ll t = 1;
    while (y) {
        if (y & 1) t = t * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return t;
}

void init() {
    memset(level, 10, sizeof(level));
    fact[0] = infa[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = 1LL * fact[i - 1] * i % MOD;
        infa[i] = 1LL * infa[i - 1] * fp(i, MOD - 2) % MOD;
    }
}

int dfs(int x) {
    int h = 1;
    for (auto y : a[x]) {
        dep[y] = dep[x] + 1;
        cnt[dep[y]]++;
        int t = dfs(y) + 1;
        h = max(t, h);
    }
    if (h < level[dep[x]]) level[dep[x]] = h;
    return high[x] = h;
}

int ans;
void get_ans(int x) {
    // cout << "x is " << x << endl;
    // printf("%d %d\n", dep[x], high[x]);
    for (auto y : a[x]) {
        int d = dep[y], h = high[y];
        if (cnt[d] >= k && h == level[d]) {
            cout << "x is "<< x << " and " << 1LL * fact[cnt[d] - 1] * infa[k - 1] % MOD << endl;
            ans += 1LL * fact[cnt[d] - 1] * infa[k - 1] % MOD;
            ans %= MOD;
        }
        get_ans(y);
    }
}

int main() {
    n = read(), k = read();
    for (int i = 2; i <= n; ++i) {
        int x = read();
        a[x].push_back(i);
    }
    dep[1] = cnt[1] = 1;
    init();
    dfs(1);
    get_ans(1);
    //for (int i = 1; i <= 4; ++i) cout << level[i] << endl;
    cout << ans << endl;
    return 0;
}