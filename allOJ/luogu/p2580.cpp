#include <bits/stdc++.h>
using namespace std;
int n, m;
int trie[1000005][26];
int cnt[1000005];
bool re[1000005];
int id;

void insert(string s) {
    int p = 0;
    for (auto i : s) {
        int x = i-'a';
        if (!trie[p][x]) trie[p][x] = ++id;
        p = trie[p][x];
    }
    ++cnt[p];
}

int find(string s) {
    int p = 0;
    for (auto i : s) {
        int x = i-'a';
        if (!trie[p][x]) return 0;
        p = trie[p][x];
    }
    if (cnt[p]) return p;
    return 0;
}

int main() {
    cin >> n;
    string s;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        insert(s);
    }
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> s;
        int t = find(s);
        if (t && !re[t]) {
            re[t] = 1;
            cout << "OK" << endl;
        } else if (re[t]) {
            cout << "REPEAT" << endl;
        } else cout << "WRONG" << endl;
    }
    return 0;
}