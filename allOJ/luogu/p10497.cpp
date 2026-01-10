#include <bits/stdc++.h>
using namespace std;
int n;
int tr[1000005];
int cow[1000005];
int use[1000005];
int high[1000005];

inline int lowbit(int x) { return x & (-x); }

inline void update(int x, int k) {
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += k;
}

inline int query(int x) {
    int sum = 0;
    for (int i = x; i; i -= lowbit(i)) sum += tr[i];
    return sum;
}

int main() {
    cin >> n;
    update(1, 1);
    for (int i = 2; i <= n; ++i) {
        cin >> cow[i];
        update(i, 1);
    }
    for (int i = n; i >= 1; --i) {
        int l = 1, r = n, id;
        while (l <= r) {
            int mid = l + r >> 1;
            if (query(mid) >= cow[i] + 1)
                id = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        high[i] = id;
        update(id, -1);
    }
    for (int i = 1; i <= n; ++i) printf("%d\n", high[i]);
    return 0;
}