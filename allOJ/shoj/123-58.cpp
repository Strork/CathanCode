#include<bits/stdc++.h>
using namespace std;
int n, m;
char s[500100];
int sum;

int main() {
    cin >> n >> m;
    int ans;
    scanf("%s", s);
    for (int i = 0; i < m; ++i) if (s[i] == '1') ++sum;
    ans = sum;
    for (int i = m; i < n; ++i) {
        if (s[i] == '1') ++sum;
        if (s[i-m] == '1') --sum;
        if (sum < ans) ans = sum;
    }
    cout << ans << endl;
    return 0;
}
