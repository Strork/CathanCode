#include <bits/stdc++.h>
using namespace std;
int ed, n, m; // 终点，石头数量，想要去掉的石头数量
int a[50010]; // 石头的位置

int read() {
    int read_num = 0, posibal = 1; char chh = 0;
    while (!isdigit(chh)) { if (chh=='-') posibal=-1;chh=getchar(); }
    while (isdigit(chh)) { read_num=read_num*10+(chh-'0');chh=getchar(); }
    return read_num * posibal;
}

int binary_search(int l, int r) {
    while (l+1 < r) {
        int mid = l+r>>1; // 当前跳跃的距离
        int now = 0; // 当前位置
        int cnt = 0; // 去掉的石头数量
        for (int i = 1; i <= n; ++i) {
            if (a[i] - now < mid) {
                ++cnt; // 比ans短，挪走
            } else now = a[i];
        }
        if (ed - now < mid) ++cnt;
        if (cnt > m) r = mid; // 移走的石头太多了，所以要让ans变小
        else l = mid;
    }
    int now = 0;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] - now < r) {
            ++cnt; // 比ans短，挪走
        } else now = a[i];
    }
    if (ed - now < r) ++cnt;
    if (cnt <= m) return r;
    else return l;
}

int main() {
    cin >> ed >> n >> m; 
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
    }
    int ans = binary_search(0, ed);
    cout << ans << endl;
    return 0;
}