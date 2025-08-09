#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
    cin >> n;
    int even = n / 2; // 偶数的数量
    int ans = even * n;
    ans -= even * (even-1) / 2; // 可以用循环代替
    cout << ans << endl;
    return 0;
}