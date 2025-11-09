#include <bits/stdc++.h>
using namespace std;
struct rain {
    int l, r;
}a[1005];
int n;

bool mycmp(rain x, rain y) { return x.l < y.l; }

void prt(int x) {
    if (x >= 1000) printf("%d", x);
    else if (x >= 100) printf("0%d", x);
    else if (x >= 10) printf("00%d", x);
    else printf("000%d", x);
}

int main() {
    freopen("rain.in", "r", stdin);
    freopen("rain.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) { 
        string s; cin >> s;
        int x = stoi(s.substr(0, 4)), y = stoi(s.substr(5, 4));
        a[i].l = x - x % 5;
        if (y % 5 != 0) a[i].r = y + 5 - (y % 5);
        else a[i].r = y;
        if (a[i].r % 100 == 60) a[i].r = (a[i].r / 100 + 1) * 100;
        // printf("%d %d\n", a[i].l, a[i].r);
    }
    sort(a + 1, a + 1 + n, mycmp);
    int st = a[1].l, ed = a[1].r;
    for (int i = 2; i <= n; ++i) {
        if (a[i].l <= ed) ed = max(ed, a[i].r); // 可以续上
        else {
            prt(st), putchar('-'), prt(ed), putchar('\n');
            st = a[i].l, ed = a[i].r;
        }
    }
    prt(st), putchar('-'), prt(ed), putchar('\n');
    return 0;
}