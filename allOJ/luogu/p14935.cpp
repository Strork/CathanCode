#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int read_num = 0, posibal = 1;
    char chh = 0;
    while (!isdigit(chh)) {
        if (chh == '-') posibal = -1;
        chh = getchar();
    }
    while (isdigit(chh)) {
        read_num = read_num * 10 + (chh - '0');
        chh = getchar();
    }
    return read_num * posibal;
}

int main() {
    int T = read();
    while (T--) {
        int r = read(), q = read(), n = read(), m = read();
        int ad = n - m / 3;
        m += q * ad;
        if (r <= m && r)
            printf("Yes\r\n");
        else
            printf("No\r\n");
    }
    return 0;
}