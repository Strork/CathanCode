#include <bits/stdc++.h>
using namespace std;
int n, k;

int main() {
    cin >> n >> k;
    n /= pow(10,k-1); // 方法一
    // for (int i = 1; i <= k-1; ++i) {
    //     n = n / 10;
    // } //方法二
    cout << n % 10 << endl;
    return 0;
}