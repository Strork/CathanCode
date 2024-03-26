#include<bits/stdc++.h>
using namespace std;
struct qaq {
    int y, v, x, nt;
}e[100100];
int lin[1000];
int len = 0;
int low[1000];
int dfn[1000];
int rev[100100];
int n, m;
int tim = 0;
int ans[100100];
int tail = 0;
struct qwq {
    int x, y;
}a[100000];
 
void insert(int x, int y, int v) {
    e[++len].nt = lin[x];
    lin[x] = len;
    e[len].y = y;
    e[len].v = v;
    e[len].x = x;
    rev[len] = len + 1;
 
    e[++len].nt = lin[y];
    lin[y] = len;
    e[len].y = x;
    e[len].v = v;
    e[len].x = y;
    rev[len] = len - 1;
}
 
void tarjan(int x, int par = 0) {
    dfn[x] = low[x] = ++tim;
    for (int i = lin[x]; i; i = e[i].nt) {
        int y = e[i].y;
        if (i != par) {
            if (!dfn[y]) {
                tarjan(y, rev[i]);
                low[x] = min(low[x], low[y]);
            }
            else low[x] = min(low[x], dfn[y]);
        }
    }
    if (dfn[x] == low[x]) ans[++tail] = par;
}
 
bool mycmp(qwq x, qwq y) {
    if (x.x == y.x) return x.y < y.y;
    else return x.x < y.x;
}
 
int main() {
    //freopen("a.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        insert(x, y, i);
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) tarjan(i);
    }
    //cout<<tail<<endl;
    for (int i = 1; i <= tail; ++i) {
        a[i].x = min(e[ans[i]].x, e[ans[i]].y);
        a[i].y = max(e[ans[i]].x, e[ans[i]].y);
    }
    sort(a + 1, a + 1 + tail, mycmp);
    for (int i = 2; i <= tail; ++i) {
        printf("%d %d\n", a[i].x, a[i].y);
    }
    return 0;
}
