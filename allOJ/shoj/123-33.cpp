#include<bits/stdc++.h>
using namespace std;
string s;
string ans;
char f2[2][2];
char f3[2][2][2];
int f[5];

int main() {
    cin >> s;
    int a = 0;
    f2[0][0] = '<';
    f2[1][1] = '>';
    f3[0][1][0] = '[';
    f3[1][0][1] = ']';
    f3[0][1][1] = '+';
    f3[1][0][0] = '-';
    for (auto i : s) {
        f[++a] = i - '0';
        if (a == 2 && f2[f[1]][f[2]]) {
            a = 0;
            ans.push_back(f2[f[1]][f[2]]);
        }
        else if (a == 3 && f3[f[1]][f[2]][f[3]]) {
            a = 0;
            ans.push_back(f3[f[1]][f[2]][f[3]]);
        }
    }
    cout << ans << endl;
    return 0;
}