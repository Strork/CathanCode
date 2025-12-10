#include <bits/stdc++.h>
using namespace std;
char ch[10005];
int n;

char dfs(int x) {
    if (ch[x]) {
        cout << ch[x];
        return ch[x];
    }
    char l = dfs(x << 1);
    char r = dfs((x << 1) + 1);
    ch[x] = (l == r) ? l : 'F';
    cout << ch[x];
    return ch[x];
}

int main() {
    cin >> n;
    for (int i = 1 << n; i < (2 << n); ++i) {
        cin >> ch[i];
        if (ch[i] == '1') ch[i] = 'I';
        else ch[i] = 'B';
    }
    dfs(1);
    return 0;
}