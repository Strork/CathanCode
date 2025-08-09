#include <bits/stdc++.h>
using namespace std;
map<int, vector<int>> a;

int read() {
    int read_num = 0, posibal = 1; char chh = 0;
    while (!isdigit(chh)) { if (chh=='-') posibal=-1;chh=getchar(); }
    while (isdigit(chh)) { read_num=read_num*10+(chh-'0');chh=getchar(); }
    return read_num * posibal;
}

int main() {
    int T = read();
    while (T--) {
        a.clear();
        int n = read();
        for (int i = 1; i <= n; ++i) {
            int x = read();
            a[x].push_back(i); // 这个数出现的坐标统计
        }
        n = read();
        for (int i = 1; i <= n; ++i) {
            int l = read(), r = read(), x = read();
            int st = lower_bound(a[x].begin(), a[x].end(), l) - a[x].begin();  // 大于等于l的第一个位置
            int ed = upper_bound(a[x].begin(), a[x].end(), r) - a[x].begin()-1; // 大于r的第一个位置，-1
            if (ed < st) printf("0\n"); 
            else printf("%d\n", ed-st+1); 
        }
    }
    return 0;
}