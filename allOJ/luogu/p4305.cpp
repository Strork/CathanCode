#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T; while (T--) {
        int n;
        cin >> n;
        unordered_map<int, bool> f; // 基于哈希表
        for (int i = 1; i <= n; ++i) {
            int x;
            scanf("%d", &x);
            if (f.find(x) != f.end()) continue;
            f[x] = 1;
            printf("%d ", x);
        }
        putchar('\n');
    }
    return 0;
}