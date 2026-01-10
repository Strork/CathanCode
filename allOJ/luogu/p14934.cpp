#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int a[N];
int n, m;

int main() {
    cin >> n >> m;
    int l = 1 << 30, r = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] < l) l = a[i];
        if (a[i] > r) r = a[i];
    }
    int dif = r - l;
    if (dif == 0)
        cout << 0 << endl;
    else if (dif % m == 0)
        cout << dif / m << endl;
    else
        cout << dif / m + 1 << endl;
    return 0;
}