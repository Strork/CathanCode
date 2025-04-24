#include<bits/stdc++.h>
using namespace std;
int n;
int ans;
int delta;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a - b > delta) delta = a - b;
        ans += b;
    }
    cout << ans + delta << endl;
    return 0;
}