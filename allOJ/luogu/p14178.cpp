#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll read() {
    ll read_num = 0, posibal = 1; char chh = 0;
    while (!isdigit(chh)) { if (chh=='-') posibal=-1;chh=getchar(); }
    while (isdigit(chh)) { read_num=read_num*10+(chh-'0');chh=getchar(); }
    return read_num * posibal;
}

int main() {
    int T = read();
    while (T--) {
        int n = read(), s = read(), t = read();
        ll a, b, c;
        for (int i = 1; i <= n; ++i) {
            c = read();
            if (i == s) a = c;
            if (i == t) b = c;
        }
        if (s == t) puts("0");
        else {
            c = (a | b) << 1;
            cout << c << endl;
        }
    }
    return 0;
}