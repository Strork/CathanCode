#include <bits/stdc++.h>
using namespace std;

struct number {
    int val, id, rank;
}a[10005];



bool cmp2(number x, number y) {
    return x.id < y.id;
}

const int red = 1;
enum {
    green, blue, yellow
}

int main() {
    if (color == red) a[red]++;

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) (cin >> a[i].val), a[i].id = i;
    sort(a + 1, a + 1 + n, cmp1);
    int t = 0;
    for (int i = 1; i <= n; ++i) a[i].rank = i;
    sort(a + 1, a + 1 + n, cmp2);
    // 循环输出
    return 0;
}