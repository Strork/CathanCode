#include <bits/stdc++.h>
using namespace std;
int f[1000005]; // 表示次数

struct block {
    int x, area;
};

bool cmp(block a, block b) {
    return (a.area > b.area) || (a.area==b.area && a.x > b.x);
}

int main() {
    f[1] = 0;
    int n;
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        if (i & 1) f[i] = f[i-1] + 1;
        else f[i] = min(f[i/2], f[i-1]) + 1;
    }
    cout << f[n] << endl;
    return 0;
}