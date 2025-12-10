#include<bits/stdc++.h>
using namespace std;
int cnt[10010];
int n, maxx;

int main() {
	cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
        maxx = max(maxx, x); // if (x > maxx) maxx = x;
    }
    for (int i = 0; i <= maxx; ++i) {
        cout << cnt[i] << endl;
    }
	return 0;
}
