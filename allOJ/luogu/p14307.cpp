#include <bits/stdc++.h>
using namespace std;
int n, m, o;

int read() {
    int read_num = 0, posibal = 1; char chh = 0;
    while (!isdigit(chh)) { if (chh=='-') posibal=-1;chh=getchar(); }
    while (isdigit(chh)) { read_num=read_num*10+(chh-'0');chh=getchar(); }
    return read_num * posibal;
}

void solution() {
    vector<int> a[25005];
    for (int i = 1; i <= n; ++i) {
        int x = read(), y = read(), v = read();
        a[x].push_back(y), a[y].push_back(x);
    }
}

int main() {
    int c = read(), T = read();
    while (T--) {
        n = read(), m = read(), o = read();
        solution();
    }    
    return 0;
}