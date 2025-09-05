#include <bits/stdc++.h>
using namespace std;
int a[2005][2005];
int dis[2005];
bool fl[2005];
int n, m;

void prim() {
    memset(dis, 10, sizeof(dis));
    dis[1] = 0;
    for (int i = 1; i <= n; ++i) {
        int t = -1;
        for (int j = 1; j <= n; ++j) {
            if (!fl[j] && (t == -1 || dis[j] < dis[t])) t = j;
        }
        if (i && dis[t] == dis[0]) 
    }
}

int main() {
    
    return 0;
}