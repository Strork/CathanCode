#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, q;
ll hp;
ll cnt, sum;

inline ll read() {
    ll read_num = 0, posibal = 1; char chh = 0;
    while (!isdigit(chh)) { if (chh=='-') posibal=-1;chh=getchar(); }
    while (isdigit(chh)) { read_num=read_num*10+(chh-'0');chh=getchar(); }
    return read_num * posibal;
}

int main() {
    n = read(), m = read(), q = read();
    hp = m;
    for (int i = 1; i <= n; ++i) {
        ll x = read();
        if (x < 0) hp += x;
        else if (hp > 0) cnt++, sum += x;
    }
    for (int i = 1; i <= q; ++i) {
        ll x = read();
        if (x * cnt + sum >= m) puts("Yes");
        else if (hp > 0) puts("Tie");
        else puts("No");
    }
    return 0;
}