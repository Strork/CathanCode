#include<bits/stdc++.h>
using namespace std;
string a, b;

int main() {
    cin >> a >> b;
    size_t ida = 0;
    for (auto i : b) {
        if (a[ida] == i && ida < a.size()) ++ida;
    }
    if (ida == a.size()) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
