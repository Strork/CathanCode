#include <bits/stdc++.h>
using namespace std;
int n, x;
int a[3005], la;

void solution() {
    memset(a, 0, sizeof(a));
    a[1] = 1; la = 1; 
    int jw = 0;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= la; ++j) {
            int t = a[j] * i + jw;
            jw = t / 10;
            a[j] = t % 10;
        }
        while (jw) {
            a[++la] = jw % 10;
            jw /= 10;
        } 
    }
    int ans = 0;
    for (int i = 1; i <= la; ++i) if (a[i] == x) ans++;
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> x;
        solution();
    }
    return 0;
}