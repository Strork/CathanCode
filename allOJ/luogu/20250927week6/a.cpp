#include <bits/stdc++.h>
using namespace std;
struct pt {
    int l, r, h, id;
}a[1004];
int n, x[1004], y[1004];

bool mycmp(pt x, pt y) { 
    if (x.h > y.h) return 1;
    else if (x.h == y.h) {
        return x.id < y.id;
    }
    return 0;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].h >> a[i].l >> a[i].r;
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n, mycmp);
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (a[j].l < a[i].l && a[j].r > a[i].l && a[j].h < a[i].h) {
                x[a[i].id] = a[j].id;
                break;
            }
        }
        for (int j = i + 1; j <= n; ++j) {
            if (a[j].l < a[i].r && a[j].r > a[i].r && a[j].h < a[i].h) {
                y[a[i].id] = a[j].id;
                break;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << x[i] << ' ' << y[i] << endl;
    }
    return 0;
}