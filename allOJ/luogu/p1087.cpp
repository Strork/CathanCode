#include <bits/stdc++.h>
using namespace std;
struct node {
    int l, r;
}a[1000005];

char dfs(int l, int r) {
    if (l == r) {
        char ch = s[l] == '0' ? 'B' : 'I'; // 0 为 B，1 为 I
        cout << ch;
        return ch;
    }
    int mid = l + r >> 1;
    char lch = dfs(l, mid);
    char rch = dfs(mid + 1, r);
    char ch = lch == rch ? lch : 'F';
    cout << ch;
    return ch;
}

int main() {
    cin >> n >> s;
    dfs(0, s.size() - 1);
    return 0;
}