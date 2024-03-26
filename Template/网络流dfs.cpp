#include<bits/stdc++.h>
#define ll long long
#define oo 100000000
int m,n;
int a[210][210];
bool f[210];
bool flag=1;
int ans=0;
int fwd=0;

void dfs(int id, int v) {
    f[id] = 1;
    if (id == n) {
        flag = 1;
        ans += v;
        fwd = v;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (a[id][i] > 0 && !f[i]) {
            dfs(i, std::min(v, a[id][i]));
            if (flag) {
                a[id][i] -= fwd;
                a[i][id] += fwd;
                return;
            }
        }
    }
}

void work() {
    while (flag) {
        flag = false;
        memset(f, 0, sizeof(f));
        dfs(1, oo);
    }
    printf("%d", ans);
}

int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        a[x][y]+=z;
    }
    work();
    return 0;
}
