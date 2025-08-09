#include <bits/stdc++.h>
using namespace std;
int n, m;
int loc[100010];

int read() {
    int read_num = 0, posibal = 1; char chh = 0;
    while (!isdigit(chh)) { if (chh=='-') posibal=-1;chh=getchar(); }
    while (isdigit(chh)) { read_num=read_num*10+(chh-'0');chh=getchar(); }
    return read_num * posibal;
}

int get_ans(int l, int r) {
    while (l+1 < r) {
        int mid = l+r>>1;
        int cnt = 1;
        int now = loc[1];
        for (int i = 2; i <= n; ++i) {
            if (loc[i] - now >= mid) {
                ++cnt;
                now = loc[i];
            }
        }
        if (cnt >= m) l = mid;
        else r = mid;
    }
    return l;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        loc[i] = read();
    }
    sort(loc+1, loc+1+n);
    cout << get_ans(loc[1], loc[n]);
    return 0;
}