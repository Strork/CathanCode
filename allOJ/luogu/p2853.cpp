
#include <bits/stdc++.h>
using namespace std;
bool vis[1005];

void dfs(int x) {
    vis[x] = 1;
    cnt[x]++;
    for (auto y : a[x]) {
        if (!vis[y]) dfs(y);
    }
}

int main() {
    
    return 0;
}