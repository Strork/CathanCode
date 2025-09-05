#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000050];

void solution() {
    a[0] = 1;
    a[1] = 1;
    for (int i = 2; i <= n; ++i) {
        int x = 0;
        for (int k = 1; k <= a[0]; ++k) {
            int t = i * a[k] + x;
            x = t / 10;
            a[k] = t % 10;
        }
        while (x) {
            a[++a[0]] = x % 10;
            x /= 10;
        }
    }
    for (int i = a[0]; i >= 1; --i) printf("%d", a[i]);
}

int main() {
    cin >> n;
    solution();
    return 0;
}