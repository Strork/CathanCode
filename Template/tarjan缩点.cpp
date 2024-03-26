#include<bits/stdc++.h>
int dfn[1010];
int low[1010];
int n;
int top;
int stack[1010];
bool vis[1010];
int tim;
int bel[1010];
int rd[1010];
int cd[1010];
int ans[5];
int num;
struct qaq {
    int y, nt;
}e[100100];
int lin[1010];
int len = 0;
 
char buf[1<<15], *fs, *ft;
inline char getc() {
    return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1<<15, stdin), fs == ft)) ? 0 : *fs++;
}
inline int read() {
    char ch = getc();
    int f = 1;
    int k = 0;
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getc();
    }
    while (isdigit(ch)) {
        k = k * 10 + ch - '0';
        ch = getc();
    }
    return k * f;
}
 
void tarjan(int x) {
    dfn[x] = low[x] = ++tim;
    vis[stack[++top] = x] = 1;
    for (int i = lin[x]; i; i = e[i].nt) {
        int y = e[i].y;
        if (!dfn[y]) {
            tarjan(y);
            low[x] = std::min(low[x], low[y]);
        }
        else if (vis[y]) low[x] = std::min(low[x], dfn[y]);
    }
    if (low[x] == dfn[x]) {
        int k;
        ++num;
        do {
            k = stack[top--];
            bel[k] = num;
            vis[k] = 0;
        } while (k != x);
    }
}
 
void solution() {
    for (int x = 1; x <= n; ++x) {
        for (int i = lin[x]; i; i = e[i].nt) {
            int y = e[i].y;
            if (bel[x] != bel[y]) {
                ++rd[bel[y]];
                ++cd[bel[x]];
            }
        }
    }
    for (int i = 1; i <= num; ++i) {
        if (!rd[i]) ++ans[1];
        if (!cd[i]) ++ans[2];
    }
    if (num == 1) printf("1\n0\n");
    else printf("%d\n%d\n", ans[1], std::max(ans[1], ans[2]));
}
 
inline void insert(int x, int y) {
    e[++len].nt = lin[x];
    lin[x] = len;
    e[len].y = y;
}
 
int main() {
    n = read();
    for (int i = 1; i <= n; ++i) {
        int x = i;
        int y = read();
        while (y) {
            insert(x, y);
            y = read();
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) tarjan(i);
    }
    solution();
    return 0;
}
