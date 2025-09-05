#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[2000010];

ll read() {
    ll read_num = 0, posibal = 1LL; char chh = 0;
    while (!isdigit(chh)) { if (chh=='-') posibal=-1;chh=getchar(); }
    while (isdigit(chh)) { read_num=read_num*10+(chh-'0');chh=getchar(); }
    return read_num * posibal;
}

int main() {
    ll T = read();
    while (T--) {
        ll n = read(), m = read();
        ll x = 0, y = 0;
        for (int i = 1; i <= n; ++i) {
            a[i] = read();
            if (a[i] > a[x]) x = i; // 第一大节点
        }
        for (int i = 1; i < n; ++i) {
            ll u = read(), v = read();
            if (u == x || v == x) {
                ll t = u ^ v ^ x;
                if (a[t] > a[y]) y = t; // 第二大节点
                else if (a[t] == a[y]) y = min(y, t);
            }
        }
        if (n == 1) {
            putchar('1'); putchar('\n'); continue;
        }
        if (a[x] - m > a[y]) { 
            printf("%d\n", x);
            continue;
        }
        // 来回横跳的部分
        ll dif = a[x] - a[y];
        m -= dif;
        if (x > y) swap(x, y); // 此时两个值相等，只需要看最终输出哪个编号
        if (m & 1) printf("%d\n", y);
        else printf("%d\n", x);
    }
    return 0;
}