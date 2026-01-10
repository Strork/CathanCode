#include <bits/stdc++.h>
using namespace std;
int n, m;
int fa[300005];

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

void baoli() {
    for (int i = 1; i <= n; ++i) fa[i] = i;
    for (int i = 1; i <= m; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        for (int j = l; j <= r; ++j) {
            if (fa[j] == j) fa[j] = x;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (fa[i] != i)
            cout << fa[i] << ' ';
        else
            cout << 0 << ' ';
    }
}

void solution() {
    for (int i = 1; i <= n; ++i) fa[i] = i;
    for (int i = 1; i <= m; ++i) {
        int l = read(), r = read(), x = read();
        for (int j = l; j <= r; ++j) {
            if (fa[j] == j) fa[j] = x;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (fa[i] != i)
            cout << fa[i] << ' ';
        else
            cout << 0 << ' ';
    }
}

int main() {
    cin >> n >> m;
    if (n <= 2004)
        baoli();
    else
        solution();
    return 0;
}