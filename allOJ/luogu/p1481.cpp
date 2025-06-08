#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int trie[N][26];
int cnt[N];
int id;

int insert(string s) {
    int ans = 0;
    int p = 0;
    for (auto i = 0; i < s.size(); ++i) {
        int x = s[i] - 'a';
        if (!trie[p][x]) trie[p][x] = ++id;
        p = trie[p][x];
        if (cnt[p]) ++ans;
    }
    ++cnt[p];
    ++ans;
    return ans;
}

int main() {
    int n;
    cin >> n;
    string s;
    int ans = -1;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        int t = insert(s);
        if (t > ans) ans = t;
    }
    
    cout << ans << endl;
    return 0;
}