#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m;
ll ans;
int university[100010];
int score[100010];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> university[i];
    sort(university + 1, university + 1 + n);
    for (int i = 1; i <= m; ++i) {
        cin >> score[i];
        int j = lower_bound(university + 1, university + 1 + n, score[i]) - university;
        int t = abs(university[j] - score[i]);
        if (j - 1 >= 1) t = min(t, abs(university[j - 1] - score[i]));
        if (j + 1 <= n) t = min(t, abs(university[j + 1] - score[i]));
        ans += t;
    }
    cout << ans << endl;
    return 0;
}