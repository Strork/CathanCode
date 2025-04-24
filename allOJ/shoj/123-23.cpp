#include<bits/stdc++.h>
using namespace std;
int cnt[10] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};

int main() {
    int n;
    cin >> n;
    int ans = 0;
    while (n) {
        ans += cnt[n%10];
        n /= 10;
    }
    cout << ans << endl;
    return 0;
}