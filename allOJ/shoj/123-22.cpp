#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    while (n) {
        int t = n % 10;
        ans += t * t * t;
        n /= 10;
    }
    cout << ans << endl;
    return 0;
}