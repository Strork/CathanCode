#include <bits/stdc++.h>
using namespace std;
int n, m, r, k;
int game[205], workTime[205], workGrade[205];
int f[205];

int main() {
    cin >> n >> m >> k >> r;
    for (int i = 1; i <= n; ++i)    cin >> game[i];
    for (int i = 1; i <= m; ++i)    cin >> workTime[i];
    for (int i = 1; i <= m; ++i)    cin >> workGrade[i];
    for (int i = 1; i <= m; ++i) {
        for (int j = r; j >= workTime[i]; --j) {
            f[j] = max(f[j], f[j - workTime[i]] + workGrade[i]);
        }
    }
    for (int i = 0; i <= r; ++i) {
        if (f[i] >= k) {
            r -= i; // 记录下还剩多少时间可以娱乐
            break;
        }
    }
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; ++i) {
        for (int j = r; j >= game[i]; --j) {
            f[j] = max(f[j], f[j - game[i]] + 1);
        }
    }
    cout << f[r] << endl;
    return 0;
}