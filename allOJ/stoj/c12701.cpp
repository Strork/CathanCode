#include <bits/stdc++.h>
using namespace std;
int n;
int a[500];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int left, right;
    cin >> left >> right;
    int sum = 0;
    for (int i = left; i <= right; ++i) {
        sum += a[i];
    }
    cout << sum << endl;
    return 0;
}