#include <bits/stdc++.h>
using namespace std;
int n;
char ch[25];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> ch;
        ch[0] = toupper(ch[0]);
        for (int j = 1; ch[j]; ++j)
            ch[j] = tolower(ch[j]);
        cout << ch << endl;
    }
    return 0;
}