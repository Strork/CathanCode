#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000005];
int atk, pet, cnt; // 攻击力、队伍数量、贪心数量

int main() {
    int T; cin >> T; while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        atk = 1, pet = 1, cnt = 0;
        bool finish = 1;
        for (int i = 1; i <= n; ++i) {
            if (a[i] == 1) ++atk, ++pet;
            else if (a[i] == -1) { // 需要献祭一次
                if (pet < 2 && !cnt) {
                    puts("-1");
                    finish = 0;
                    break;
                } else {
                    if (pet < 2) ++atk, ++pet, --cnt; // 回退操作，之前的分岔取消一次献祭
                    else --pet;
                }
            } else {
                if (pet < 2) ++atk, ++pet; // 没法贪心献祭
                else --pet, ++cnt; // 记录一次贪心献祭
            }
        }
        if (finish) {
            int gcdab = __gcd(atk, pet);
            printf("%d %d\n", atk / gcdab, pet / gcdab);
        }
    }
    return 0;
}