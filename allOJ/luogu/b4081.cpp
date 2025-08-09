#include <bits/stdc++.h>
using namespace std;
struct contest {
    int first, second;
}a, b, c, d;
int ans = 0;

int main() {
    cin >> a.first >> b.first >> c.first >> d.first;  // cin 读入
    scanf("%d %d %d %d", &a.second, &b.second, &c.second, &d.second); // scanf读入
    if ((a.first - b.first) * (a.second - b.second) < 0) ++ans; // a and b
    if ((a.first - c.first) * (a.second - c.second) < 0) ++ans; // a and c
    if ((a.first - d.first) * (a.second - d.second) < 0) ++ans; // a and d
    if ((b.first - c.first) * (b.second - c.second) < 0) ++ans; // b and c
    if ((b.first - d.first) * (b.second - d.second) < 0) ++ans; // b and d
    if ((c.first - d.first) * (c.second - d.second) < 0) ++ans; // c and d
    cout << ans << endl;
    return 0;
}