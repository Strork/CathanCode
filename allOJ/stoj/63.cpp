#include <bits/stdc++.h>
using namespace std;
int y, m, d;

int main() {
    cin >> y >> m >> d;
    int ans = 0;
    if (m == 1) ans += d;
    else ans += 31;
    if (m == 2) ans += d;
    else if (y%4==0 && y%100!=0 || y%400==0) ans += 29;
    else ans += 28;
    if (m == 3) ans += d;
    else ans += 31;
    
    return 0;
}