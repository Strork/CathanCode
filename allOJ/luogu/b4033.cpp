#include <bits/stdc++.h>
using namespace std;
int a[1005], b[1005], c[1005];
int n;

int main() {
    cin >> n;
    int win = 0, lose = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 1; i <= n; ++i) {
        c[i] = b[i] - a[i];
        if (c[i] > 0)
            lose++;
        else if (c[i] < 0)
            win++;
    }
    if (win > lose)
        cout << 0 << endl;
    else {
        int sum = 0;
        sort(c + 1, c + 1 + n);
        for (int i = 1; i <= n; ++i) {
            if (c[i] == 0) {
                sum++;
                win++;
            } else if (c[i] > 0) {
                sum += c[i];
                lose--;
            }
            if (win > lose) break;
        }
        cout << sum << endl;
        return 0;
    }
}