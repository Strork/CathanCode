#include <bits/stdc++.h>
#define mmst(x) memset(x, 0, sizeof(x))
using namespace std;
int a[10][10], b[10][10];
int s[200005];
int n, k, q;

inline int read() {
    int read_num = 0, posibal = 1; char chh = 0;
    while (!isdigit(chh)) { if (chh=='-') posibal=-1;chh=getchar(); }
    while (isdigit(chh)) { read_num=read_num*10+(chh-'0');chh=getchar(); }
    return read_num * posibal;
}

inline void addEdge(int *v, int &i, int &y) {
    for (int p = 0; p <= 9; ++p) {
        if (v[p] > 0) {
            if (!a[p][y] || a[p][y] == i) a[p][y] = i;
            else b[p][y] = 1; // 有几个人能接上这段龙
        }
    }
}

int main() {
    int T = read(); while (T--) {
        mmst(a), mmst(b);
        n = read(), k = read(), q = read();
        for (int i = 1; i <= n; ++i) { // 建立边
            int m = read();
            int v[10] = {}; // 空数组统计出现的字符
            for (int j = 1; j <= m; ++j) {
                s[j] = read();
                if (j - k > 0) --v[s[j - k]]; // 删除区间外的数
                addEdge(v, i, s[j]);
                ++v[s[j]]; // 标记当前数字
            }
        }
        
    }
    return 0;
}