#include <bits/stdc++.h>
#define ll long long
using namespace std;
map<string, int> a;
priority_queue<pair<int, int>, vector<int>, greater<int>> q;

int main() {
    a["abc"] = 2;
    a["ab"] = 3;
    for (auto it = a.begin(); it != a.end(); it++) {
        cout << it->first << ' ' << it->second << endl;
    }
    b.x = 1;
    b.y = 2;
    node* p = &b;
    return 0;
}