#include <bits/stdc++.h>
using namespace std;
int trie[1000005][26];
int len;
int cnt[1000005];
int n, m;

void insert(string* s) {
    int p = 0;
    for (auto i : *s) {
        int x = i - 'a';
        if (!trie[p][x]) trie[p][x] = ++len;
        p = trie[p][x];
    }
    ++cnt[p];
}

int find(string* s) {
    int ans = 0;
    int p = 0;
    for (auto i : *s) {
        int x = i - 'a';
        if (cnt[p]) ans += cnt[p];
        if (!trie[p][x]) return ans;
        p = trie[p][x];
        if (!p) return ans;
    }
    if (cnt[p]) ans += cnt[p];
    return ans;
}

int main() {
    cin >> n >> m;
    string s;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        insert(&s);
    }
    for (int i = 1; i <= m; ++i) {
        cin >> s;
        cout << find(&s) << endl;
    }
    return 0;
}