#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;
ll a, x, b;
ll num[25];

// 1 2 3 5 8 13
// 2 3 5 8 13 21
// 3 4 7 11 18 29
// 10 11 21 32
int main() {
    num[0] = 1;
    num[1] = 1;
    num[2] = num[1] + 1;
    for (int i = 3; i <= 21; ++i) {
        num[i] = num[i-1] + num[i-2];
    }
    int T;
    cin >> T;
    bool flag;
    while (T--) {
        cin >> a >> x >> b;
        flag = 0;
        if (a == 1) flag = 1;
        else if (a == 2 && x >= 2) flag = 1; 
        else if (a == 3 && x >= 3 && (x&1) ) flag = 1;
        else if (a >= 4 && (x == num[a] || (x - num[a]) % num[a-1] == 0)) {
            flag = 1;
        }
        if (!flag) cout << -1 << endl;
        else {
            if (x == num[a]) cout << num[b] << endl;
            else {
                ll t;
                if (a == 1) t = x-1;
                else if (a == 2) t = x-2;
                else t = (x - num[a]) / num[a-1];
                cout << num[b] + t*num[b-1] << endl;
            }
        }
    }
    return 0;
}