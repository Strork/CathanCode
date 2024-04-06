#include<bits/stdc++.h>
using namespace std;
int n;
int a[50100];
int cnt = 0;

int main() {
    cin >> n;
    int t;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &t);
        if (a[t] == 0) ++cnt;
        ++a[t];
    }
    cout << cnt - 1 << endl;
    return 0;
}