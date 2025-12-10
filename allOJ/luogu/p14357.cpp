#include <bits/stdc++.h>
using namespace std;
int cnt[333];

int main() {
    string str; cin >> str;
    for (auto x : str) cnt[x]++;
    for (int i = '9'; i >= '0'; --i) {
        while (cnt[i]--) printf("%d", i - '0');
    }
    return 0;
}