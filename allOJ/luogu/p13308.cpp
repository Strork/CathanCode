#include <bits/stdc++.h>
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
#define FA(x) (x>>1)
#define ll long long
using namespace std;
int n, m;
ll ans = 0;
int cnt[1100000];
bool opt[1100000];

inline ll read() {
    ll read_num = 0, posibal = 1; char chh = 0;
    while (!isdigit(chh)) { if (chh=='-') posibal=-1;chh=getchar(); }
    while (isdigit(chh)) { read_num=read_num*10+(chh-'0');chh=getchar(); }
    return read_num * posibal;
}

int build(int x, int depth) {
    cnt[x] = 1;
    if (depth == n) return 1;
    int l = build(L(x), depth + 1);
    int r = build(R(x), depth + 1);
    cnt[x] += l + r;
    return cnt[x];
}

void baoli() {
    build(1, 1);
    opt[1] = 1;
    for (int i = 1; i <= m; ++i) {
        int o, u;
        cin >> o >> u;
        if (o == 1 && !opt[u]) {
            int t = u;
            while (!opt[t]) {
                t = FA(t);
                cnt[t] -= cnt[u];
            }
            opt[u] = 1;
        } else if (o == 2) {
            while (!opt[u]) u = FA(u);
            ans ^= cnt[u];
        }
    }
    cout << ans << endl;
}

struct Trie {
    ll sum;
    bool cut;
    int son[2];
}a[21000000];
int id;
int path[65];

void find(ll u, int h) {
    int p = 1, pu = 1;
    while((1LL << pu) <= u) ++pu;
    pu -= 2; // 找到下一个节点的位置
    path[pu+1] = 1, path[pu+2] = 0; // 往回找走了哪些点的话，最后一个一定是根，0用来结束循环
    while (pu >= 0) {
        --h;
        short b = u >> pu & 1;
        if (!a[p].son[b]) { // 需要新建节点的话
            a[p].son[b] = ++id;
            a[id].sum = (1LL << h) - 1; // 新节点的 sum 值
        }
        p = a[p].son[b];
        path[pu] = p; // 记录经过的 Trie 节点 id
        --pu;
    }
}

void solution() {
    a[0].cut = 1;
    a[1].sum = (1LL << n) - 1;
    id = 1;
    for (int i = 1; i <= m; ++i) {
        int o; ll u;
        o = read(); u = read();
        if (o == 1 && u != 1) {
            find(u, n); // path 数组中path[0]是 u 节点，path[1]是父节点...
            for (int p = 1; path[p]; ++p) {
                if (a[path[p-1]].cut) break;
                a[path[p]].sum -= a[path[0]].sum;
            }
            a[path[0]].cut = 1; // u 点删除边
        } else if (o == 2) {
            find(u, n);
            int p = 0;
            while (!a[path[p]].cut) ++p;
            if (path[p] == 0) ans ^= a[1].sum;
            else ans ^= a[path[p]].sum;
        }
    }
    cout << ans << endl;
}

int main() {
    n = read(), m = read();
    if (n <= 20) baoli(); // 比赛时，只要暴力写的对，小数据就用暴力跑，保证一定有分
    else solution();
    return 0;
}