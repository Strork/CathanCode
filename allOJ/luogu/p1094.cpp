#include <bits/stdc++.h>
using namespace std;
int w, n, a[30010];
int ans;

int main() {
    cin >> w >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n); // 我们要排序，这样方便我们每次选择价值最大的这一件物品
    int l = 1, r = n; // 排好序之后，我们每次的目光只有两个物品：最贵的和最便宜的
    while (l <= r) {
        if (a[l] + a[r] <= w) ++ans, ++l, --r; // 两件物品可以成一组
        else ++ans, --r; // 如果不行，贵的一定只能单独成一组了
    }
    cout << ans << endl; // 最后输出组数
    return 0;
}