#include <bits/stdc++.h>
using namespace std;
int n, q;
int a[100010];

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= q; ++i) {
        int l, r;
        cin >> l >> r; // 排好序，二分查找 l 与 r 区间
        int x = lower_bound(a + 1, a + 1 + n, l) - a; // 第一个 >= l 的下标
        int y = upper_bound(a + 1, a + 1 + n, r) - a; // 第一个 > r 的下标
        printf("%d\n", y - x);
    }
    return 0;
}