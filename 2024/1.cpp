#include <bits/stdc++.h>
using namespace std;
char ch[100100];

int main() {
    int n, k;
    int ans = 0;
    while (cin >> n >> k) { // 注意 while 处理多个 case
        scanf("%s", &ch);
        for (int i = 0; i < n; ++i) {
            if (ch[i] == 'M' || ch[i] == 'T') ans++;
            else if (k > 0) {
                ans++;
                k--;
            }
        }
        if (ans > n) ans = n;
        cout << ans << endl;
    }
}
// 64 位输出请用 printf("%lld")