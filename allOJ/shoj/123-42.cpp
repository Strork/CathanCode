#include<bits/stdc++.h>
using namespace std;
int yy, mm, dd;
int d[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    char ch;
    cin >> yy >> ch >> mm >> ch >> dd;
    int ans = 0;
    if (yy % 4 == 0 && yy % 100 != 0 || yy % 400 == 0) d[2] = 29;
    for (int i = 1; i < mm; ++i) ans += d[i];
    ans += dd;
    cout << ans << endl;
    return 0;
}