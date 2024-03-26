#include<bits/stdc++.h>
#define ll long long
#define reg register int
using namespace std;

int a[100100];
int b[100100];
int n, m;

inline int read() {
    int k = 0;
    char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) { k = k * 10 + ch - '0'; ch = getchar(); }
    return k;
}

int main() {
    n = read(), m = read();
    for (reg i = 1; i <= n; ++i) {
        a[i] = read();
    }
    for (reg i = 1; i <= m; ++i) {
        int op = read();
        if (op == 1) {
            int l = read(), r = read(), x = read();
            for (reg j = l; j <= r; ++j) {
                a[j] ^= x;
            }
        }
        else if (op == 2) {
            int l = read(), r = read();
            for (reg j = l; j <= r; ++j) b[j - l] = a[j];
            sort(b, b + r - l + 1);
            for (reg j = l; j <= r; ++j) a[j] = b[j - l];
        }
        else if (op == 3) {
            int ans = 0;
            int l = read(), r = read();
            for (reg j = l; j <= r; ++j) ans ^= a[j];
            printf("%d\n", ans);
        }
    }
    return 0;
}
