#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m, q, u, v, t;
int a[100100];
typedef pair<int, int> pii;
queue<int> worm[3];

int main() {
    cin >> n >> m >> q >> u >> v >> t;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a+1, a+1+n, greater<int>());
    for (int i = 1; i <= n; ++i) {
        worm[0].push(a[i]);
    }
    // 切割
    for (int i = 1; i <= m; ++i) {
        int delta = (i-1)*q; // 蚯蚓这段时间涨了多长，偏移量
        pii tmp = max({make_pair(worm[0].empty() ? -1123456789 : worm[0].front(), 0), 
                       make_pair(worm[1].empty() ? -1123456789 : worm[1].front(), 1), 
                       make_pair(worm[2].empty() ? -1123456789 : worm[2].front(), 2)});
        int x = tmp.first + delta; // 蚯蚓的真实长度，计算切割后的长度一定要使用真实长度
        int b = 1LL * x * u / v;
        worm[1].push(b-q-delta);
        worm[2].push(x-b-q-delta); // 入队时使用原始长度
        worm[tmp.second].pop(); // 被切掉的蚯蚓出列
        if (i % t == 0) printf("%d ", x);
    }
    putchar('\n');
    for (int i = 1; i <= n+m; ++i) {
        pii tmp = max( {make_pair(worm[0].empty() ? -1123456789 : worm[0].front(), 0), 
                        make_pair(worm[1].empty() ? -1123456789 : worm[1].front(), 1), 
                        make_pair(worm[2].empty() ? -1123456789 : worm[2].front(), 2)});
        if (i % t == 0) printf("%d ", tmp.first + m*q);
        worm[tmp.second].pop();
    }
    return 0;
}
