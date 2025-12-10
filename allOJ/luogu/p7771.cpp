#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[100005];
vector<int> ans;
int rd[100005], cd[100005];
int s, t;

bool check_ola() {
    for (int i = 1; i <= n; ++i) {
        if (rd[i] - 1 == cd[i]) {
            if (t != 0) return 0;
            t = i;
        } else if (cd[i] - 1 == rd[i]) {
            if (s != 0) return 0;
            s = i;
        } else if (rd[i] != cd[i]) return 0;
    }
    return 1;
}

void dfs(int x) {
    while (a[x].size()) {
        int y = a[x].back();
        a[x].pop_back();
        dfs(y);
        ans.push_back(y);
    }
}

void get_ola() {
    if (!s) {
        for (int i = 1; i <= n; ++i) {
            if (rd[i] + cd[i] > 0) {
                dfs(i);
                ans.push_back(i);
                break;
            }
        }
    } else {
        dfs(s);
        ans.push_back(s);
    }
    if (ans.size() != m + 1) printf("No\n");
    else {
        for (int i = ans.size() - 1; i >= 0; --i) {
            printf("%d ", ans[i]);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        a[x].push_back(y);
        rd[y]++, cd[x]++;
    }
    bool ola = check_ola();
    if (!ola) printf("No\n");
    else {
        for (int i = 1; i <= n; ++i) {
            sort(a[i].begin(), a[i].end(), greater<int>());
        }
        get_ola();
    }
    return 0;
}