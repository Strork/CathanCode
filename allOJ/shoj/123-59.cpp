#include<bits/stdc++.h>
using namespace std;
int n;
int a[100100];
int maxx = -12343211;
int ans = 0;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) {
        if (a[i] > maxx) maxx = a[i];
        if (maxx - a[i] > ans) ans = maxx - a[i];
    }
    cout << ans << endl;
    return 0;
}
