#include <bits/stdc++.h>
using namespace std;
int w0, w, m;

bool check(int mid) {
    double x = mid / 10000.0;
    double sum = 0.0;
    for (int i = 1; i <= m; ++i) {
        sum += w * 1.0 / pow(x + 1.0, i);
    }
    return sum >= w0;
}

int main() {
    cin >> w0 >> w >> m;
    int l = 1, r = 30000;
    int ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) l = mid + 1, ans = mid; // 找最小的利率
        else r = mid - 1;
    }
    double outp = ans / 100.0;
    printf("%.1lf", outp);
    return 0;
}