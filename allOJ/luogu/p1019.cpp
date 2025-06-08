#include <bits/stdc++.h>
using namespace std;
int vis[25];
string str[25];
int n;

void dfs(string tmp) {
    for () {
        if (vis[i] <= 2) {
            tmp.substr(tmp.size() - j)  str[i].substr(0, j) dfs
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> str[i];
    }
    char ch;
    cin >> ch;
    for (int i = 1; i <= n; ++i) {
        if (str[i][0] == ch) {
            vis[i]++;
            dfs(str[i]);
            vis[i]--;
        }
    }
    return 0;
}