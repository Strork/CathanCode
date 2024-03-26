#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, q;
int num[100100];
ll sum, k;
ll l, r;
ll ansMin, ansMax;

int main() {
    int n, q;
    cin >> n >> q;
    sum = k = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &num[i]);
        if (num[i] == 0) ++k;
        else sum += num[i];
    }
    for (int i = 1; i <= q; ++i) {
        ansMin = ansMax = 0;
        scanf("%lld %lld", &l, &r);
        ansMin = sum + k * l;
        ansMax = sum + k * r;
        printf("%lld %lld\n", ansMin, ansMax);
    }
}
// 64 位输出请用 printf("%lld")