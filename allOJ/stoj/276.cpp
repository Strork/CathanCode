#include <bits/stdc++.h>
using namespace std;
int na[205], nb[205], nc[205];
int lena, lenb, lenc;

string del(string a, string b) {
    lena = a.size(), lenb = b.size();
    if (lena < lenb || lena == lenb && a < b) {
        printf("-");
        swap(a, b);
        swap(lena, lenb);
    }
    for (int i = 0; i < lena; ++i) na[lena - i] = a[i] - '0';
    for (int i = 0; i < lenb; ++i) nb[lenb - i] = b[i] - '0';
    for (int i = 1; i <= lena; ++i) {
        if (na[i] < nb[i]) {
            na[i + 1]--;
            na[i] += 10;
        }
        nc[i] = na[i] - nb[i];
    }
    lenc = lena;
    while (!nc[lenc] && lenc > 1) lenc--;
    string ans;
    for (int i = lenc; i >= 1; i--) ans += char(nc[i] + '0');
    return ans;
}

int main() {
    string aa, bb;
    cin >> aa >> bb;
    cout << del(aa, bb);
    return 0;
}