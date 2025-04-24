#include<bits/stdc++.h>
using namespace std;
int n;
int a[100100];

int main() {
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (a[a[i]] == i) ++ans;
    }
    cout << ans << endl;
    return 0;
}