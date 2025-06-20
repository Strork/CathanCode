#include <bits/stdc++.h>
using namespace std;
int trie[1000005][2];
int id;
int ans = 0;

void insert(int s) {
    int p = 0;
    int sum = 0;
    while (s >= 0) {
        int x = s&1;
        if (!trie[p][x]) trie[p][x] = ++id;
        
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int s;
        cin >> s;
        insert(s);
    }
    return 0;
}