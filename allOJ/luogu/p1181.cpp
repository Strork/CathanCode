#include <bits/stdc++.h>
using namespace std;
int a[100005];
int n, m;
int sum = 0;

void binary_search(int l, int r) {
    while (l+1 <= r) {
        int mid = l + (r-l)/2;
        int cnt = 1;
        for (int i = 1; i <= n; ++i) {
            if (sum + a[i] <= mid) {
                sum += a[i];
            } else {
                ++cnt;
                sum = a[i];
            }
        }
        if (cnt > m) l = mid+1;
        else r = mid;
    }
    cout << l << endl;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    binary_search(1, 1e8);
    return 0;
}