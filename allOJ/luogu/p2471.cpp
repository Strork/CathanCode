#include <bits/stdc++.h>
using namespace std;
int st[500005][20];
int a[500005];
int n, m;

void get_st() {
    int k = log2(n);
    for (int j = 1; j <= k; ++j) {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j-1))][j-1]);
        }
    }
}

inline int find(int x, int y) {
    int p = log2(y - x + 1); // 区间长度 2^p
    return max(st[x][p], st[y - (1 << p) + 1][p]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &a[i], &st[i][0]);
    }
    get_st();
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        int div = r - l + 1;
        l = lower_bound(a + 1, a + 1 + n, l) - a;
        r = lower_bound(a + 1, a + 1 + n, r) - a;
        if (r == l + 1) {
            if (div == 2) puts("true"); // 年份相差 1，必然为 true
            else puts("maybe"); // 已知信息相差 1，但是缺少年份
        } else {
            int maxx = find(l + 1, r - 1);
            if (maxx >= st[r][0]) puts("false");
            else if (r - l + 1 == div) puts("true");
            else puts("maybe");
        }
    }
    return 0;
}