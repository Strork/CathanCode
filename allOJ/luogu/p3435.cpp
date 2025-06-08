#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
string s;
int p[1001000];
ll sum = 0;

int main() {
    cin >> n >> s;
    for (int i = 1; i < n; ++i) {
        int len = p[i-1];
        while (len && s[i] != s[len]) len = p[len-1];
        if (s[i] == s[len]) p[i] = len + 1;
    }
    for (int i = 1; i < n; ++i) {
        int len = p[i];
        while (len>=1 && p[len-1]>0) {
            len = p[len-1];
        }
        p[i] = len;
        if (len) sum += i+1 - len;
    }
    cout << sum << endl;
    return 0;
}