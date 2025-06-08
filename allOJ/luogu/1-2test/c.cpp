#include <bits/stdc++.h>
using namespace std;
int n;
int a[1005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int t;
        scanf("%d", &t);
        a[t]++;
    }
    for (int i = 1; i <= 1000; ++i) {
        if (a[i]) cout << i << ' ' << a[i] << endl;
    }
    return 0;
}