// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 5;
// struct node {
//     int y, nt;
// }e[N<<1];
// int n, id;
// int lin[N], ans = N;
// int ansid = N;

// void adde(int x, int y) {
//     e[id].y = y;
//     e[id].nt = lin[x];
//     lin[x] = id++;
// }

// int dfs(int x, int father) {
//     int sum = 1, res = 0;
//     for (int i = lin[x]; i; i = e[i].nt) {
//         int y = e[i].y;
//         if (y == father) continue;
//         int t = dfs(y, x);
//         sum += t;
//         res = max(res, t);
//     }
//     res = max(res, n - sum);
//     //ans = min(ans, res); // 修改ans的地方
//     if (res <= ans) {
//         ans = res; // 重心旁边的子树大小
//         if (x < ansid) ansid = x; // 记录重心是谁
//     }
//     return sum;
// }

// int main() {
//     cin >> n;
//     int x, y;
//     for (int i = 1; i < n; ++i) {
//         cin >> x >> y;
//         adde(x, y); adde(y, x);
//     }
//     dfs(1, 0);
//     cout << ansid << endl;
//     return 0;
// }

#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> a[1000010];
int s[1000010];
int depth[1000010];
ll f[1000010];
int n;
ll ans = 1234567890ll;

void get_s(int x, int fa) {
    s[x] = 1;
    if (x != fa) depth[x] = depth[fa] + 1;
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

void p(int x) {cout << x << endl;}

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
