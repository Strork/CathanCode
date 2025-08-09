#include <bits/stdc++.h>
using namespace std;
int n;
int a[4], b[4];

int main() {
    cin >> n;
    int money = 12345652;
    for (int i = 1; i <= 3; ++i) {
        cin >> a[i] >> b[i];
        int cnt = n / a[i];
        if (n % a[i] != 0) ++cnt;
        money = min(money, cnt * b[i]);
    }
    cout << money;
    return 0;
}