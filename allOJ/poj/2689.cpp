#include<cctype>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define ll long long
#define reg register int

using std::cout;

int l, r;
int prime[1001000];
int v[1001000];
int a[1001000];
bool f[1000100];
int tot = 0;
int m = 0;

inline int read() {
    int k = 0;
    char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) { k = k * 10 + ch - '0'; ch = getchar(); }
    return k;
}

void primes(int n) {
    memset(v, 0, sizeof(v));
    m = 0;
    for (reg i = 2; i <= n; ++i) {
        if (v[i] == 0) v[i] = i, prime[++m] = i;
        for (reg j = 1; j <= m; ++j) {
            if (prime[j] > v[i] || prime[j] > n / i) break;
            v[i * prime[j]] = prime[j];
        }
    }
    //cout << "****";
}

int main() {
    primes(46340);
    while ((l = read()) && (r = read())) {
        //primes(std::sqrt(r));
        //cout << "-----";
        tot = 0;
        memset (f, 1, sizeof(f));
        f[0] = 0;
        if (l == 2) f[0] = 1;//Warning!
        for (reg i = 1; i <= m; ++i) {
            for (reg j = l / prime[i]; j <= r / prime[i]; ++j) {
                if (j > 1) f[prime[i] * j - l] = 0;
            }
        }
        for (reg i = l; i <= r; ++i) {
            if (f[i - l]) a[++tot] = i;
            if (i == r) break;//Warning!
        }
        if (tot < 2) printf("There are no adjacent primes.\n");
        else {
            int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
            int minn = 2147483647;
            int maxx = 0;
            for (reg i = 1; i < tot; ++i) {
                if (a[i + 1] - a[i] < minn) {
                    a1 = a[i], a2 = a[i + 1];
                    minn = a2 - a1;
                }
                if (a[i + 1] - a[i] > maxx) {
                    a3 = a[i], a4 = a[i + 1];
                    maxx = a4 - a3;
                }
            }
            printf("%d,%d are closest, %d,%d are most distant.\n", a1, a2, a3, a4);
        }
    }
    return 0;
}
