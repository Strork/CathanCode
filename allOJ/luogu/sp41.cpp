#include <bits/stdc++.h>
#define mmst(x) memset(x, 0, sizeof(x))
using namespace std;
int rd[30], cd[30], fa[30];
bool f[30];
int n;

int getfa(int x) {
    if (fa[x] == x) return x;
    fa[x] = getfa(fa[x]);
    return fa[x];
}

inline void merge(int x, int y) {
    int rx = getfa(x), ry = getfa(y);
    if (rx != ry) fa[rx] = ry;
}

bool check_ola() {
    int s = 0, t = 0;
    for (int i = 0; i < 26; ++i) {
        if (rd[i] - 1 == cd[i]) {
            if (t != 0) return false;
            t = i;
        } else if (cd[i] - 1 == rd[i]) {
            if (s != 0) return false;
            s = i;
        } else if (rd[i] != cd[i]) return false;
    }
    return true;
}

int main() {
    int T; cin >> T;
    while (T--) {
        mmst(rd), mmst(cd), mmst(f);
        for (int i = 0; i < 26; ++i) fa[i] = i;
        cin >> n;
        while (n--) {
            string str; cin >> str;
            int x = str.front() - 'a';
            int y = str.back() - 'a';
            merge(x, y);
            cd[x]++, rd[y]++, f[x] = f[y] = 1;
        }
        int g = 0;
        for (int i = 0; i < 26; ++i) {
            fa[i] = getfa(i);
            if (f[i] && fa[i] == i) g++;
        }
        if (g != 1) puts("The door cannot be opened.");
        else {
            if (check_ola()) puts("Ordering is possible.");
            else puts("The door cannot be opened.");
        }
    }
    return 0;
}