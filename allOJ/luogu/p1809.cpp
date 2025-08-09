#include <bits/stdc++.h>
using namespace std;
int n;
int a[100010];

int read() {
    int read_num = 0, posibal = 1; char chh = 0;
    while (!isdigit(chh)) { if (chh=='-') posibal=-1;chh=getchar(); }
    while (isdigit(chh)) { read_num=read_num*10+(chh-'0');chh=getchar(); }
    return read_num * posibal;
}

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
    }
    sort(a+1, a+1+n);
    long long ans = 0ll;
    while (n >= 4) {
        if (a[1] + a[n-1] < a[2] + a[2]) {
            ans += a[n] + a[1];
            --n;
        } else {
            ans += a[2] + a[1] + a[n] + a[2];
            n -= 2;
        }
    }
    if (n == 1) ans += a[1];
    else if (n == 2) ans += a[2];
    else ans += a[1] + a[2] + a[3];
    cout << ans << endl;
    return 0;
}