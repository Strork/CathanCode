#include <bits/stdc++.h>
using namespace std;
int n, m;
struct student {
    int myself, to;
}a[2000005];

bool mycmp(student x, student y) { return x.to < y.to; }

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &a[i].to);
        a[i].myself = i;
    }
    sort(a+1, a+1+m, mycmp);
    for (int i = 1; i <= m; ++i) {
        printf("%d ", a[i].to);
    }
    return 0;
}