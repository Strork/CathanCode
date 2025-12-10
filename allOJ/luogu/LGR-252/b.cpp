#include <bits/stdc++.h>
using namespace std;
int n, m, k;
double dis[100005];
vector<int> a[100005];

inline int read() {
    int read_num = 0, posibal = 1; char chh = 0;
    while (!isdigit(chh)) { if (chh=='-') posibal=-1;chh=getchar(); }
    while (isdigit(chh)) { read_num=read_num*10+(chh-'0');chh=getchar(); }
    return read_num * posibal;
}



int main() {
    int T = read(); while (T--) {
        n = read(), m = read(), k = read();
        for (int i = 1; i <= n; ++i) a[i].clear(), dis[i] = -1;
        for (int i = 1; i <= m; ++i) {
            int x = read(), y = read();
            a[x].push_back(y), a[y].push_back(x);
        }
        int x = read(), y = read();
    }
    return 0;
}