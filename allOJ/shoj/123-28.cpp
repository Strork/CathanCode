#include<bits/stdc++.h>
using namespace std;
int n;
int a;
int hel;
int ans = 1;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a);
        hel += a;
        if (hel <= 0) ans = max(ans, 1 - hel);
    }
    cout << ans << endl;
    return 0;
}