#include <bits/stdc++.h>
using namespace std;
struct student {
    int c, m, e;
    int cme, cm;
    int id;
    int rnk;
    bool operator==(const student &x) const {
        return cme == x.cme && cm == x.cm && max(x.c, x.m) == max(c, m);
    }
}a[10005];
int n;

bool mycmp(student x, student y) {
    if (x.cme > y.cme) return true;
    else if (x.cme == y.cme) {
        if (x.cm > y.cm) return true;
        else if (x.cm == y.cm) {
            int tx = max(x.c, x.m);
            int ty = max(y.c, y.m);
            return tx > ty;
        }
    }
    return false;
}

bool cmpid(student x, student y) { return x.id < y.id; }

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].c >> a[i].m >> a[i].e;
        a[i].cm = a[i].c + a[i].m;
        a[i].cme = a[i].cm + a[i].e;
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n, mycmp);
    a[1].rnk = 1;
    for (int i = 2; i <= n; ++i) {
        if (a[i] == a[i - 1]) a[i].rnk = a[i - 1].rnk;
        else a[i].rnk = i;
    }
    sort(a + 1, a + 1 + n, cmpid);
    for (int i = 1; i <= n; ++i) printf("%d\n", a[i].rnk);
    return 0;
}