#include <bits/stdc++.h>
using namespace std;
struct tr {
    int l, r;
    int high;
}tree[1001000];

int dfs(int x) {
    if (!x) return 0;
    
    int left_high = dfs(tree[x].l);
    int right_higt = dfs(tree[x].r);
    tree[x].high = max(left_high, right_higt) + 1;
}

int main() {
    dfs(1);
    return 0;
}