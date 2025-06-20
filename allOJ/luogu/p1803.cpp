#include <bits/stdc++.h>
using namespace std;
struct p1803 {
    int x, y;
}a[1000010];


bool mycmp(p1803 x, p1803 y) { return x.y < y.y; }

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &a[i].x, &a[i].y);
    }
    sort(a+1, a+1+n, mycmp);
    int ans = 0;
    int now = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i].x >= now) {
            ++ans;
            now = a[i].y;
        }
    }
    cout << ans << endl;
    return 0;
}