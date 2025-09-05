#include <bits/stdc++.h>
using namespace std;
struct stu {
    int id, chn, math, eng;
    int tot;
    void gtot() {
        tot = chn + math + eng;
    }
};
stu a[305];

bool mycmp(stu x, stu y) {
    if (x.tot > y.tot) return 1; // 总分大
    if (x.tot == y.tot) { // 如果总分相等
        if (x.chn > y.chn) return 1; // 语文靠前
        if (x.chn == y.chn) return x.id < y.id; // 语文相等，学号靠前
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].chn >> a[i].math >> a[i].eng;
        a[i].gtot();
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n, mycmp);
    int t = 5;
    if (n < t) t = n;
    for (int i = 1; i <= t; ++i) {
        cout << a[i].id << ' ' << a[i].tot << endl;
    }
    return 0;
}