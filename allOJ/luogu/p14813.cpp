#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
bool is_prime = true;
int b;
ll ans = 0;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        is_prime = true;
        b = n;
        ans = 0;
        for (int i = 2; i < b; ++i) {
            if (n % i == 0) {  // 有变化
                ans += b * i - n;
                b = n / i;
                is_prime = false;  // 不是质数
            }
            if (i >= b) break;
            ans += b;
            if (i * i > n && is_prime) break;  // 如果是质数，提前结束判断
        }
        ans += 1 + n;
        if (is_prime) ans = 1LL * n * (n - 1) + 1;
        printf("%lld\n", ans);
    }
    return 0;
}