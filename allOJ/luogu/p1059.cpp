#include <bits/stdc++.h>
using namespace std;
int n, m;
bool a[1005];
string a;

char dfs(int l, int r) {
    if (l == r) {
        cout << (a[l] == '0') ? 'B' : 'I';
        return a[l] == '0' ? 'B' : 'I';
    }
    int mid = (l+r)/2;
    char cl = dfs(l, mid);
    char cr = dfs(mid+1, r);
    char tmp = ((cl == cr) ? cl : 'F');
    cout << tmp;
    return tmp;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if (!a[x]) m++;
        a[x] = 1;
    }
    cout << m << endl;
    for (int i = 1; i <= 1000; ++i) {
        if (a[i]) cout << i << ' ';
    }
    return 0;
}