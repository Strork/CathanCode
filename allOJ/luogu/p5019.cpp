#include <bits/stdc++.h>
using namespace std;
int sum, n, a[100005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] > a[i - 1]) sum += a[i] - a[i - 1];
    }
    cout << sum << endl;
    return 0;
}