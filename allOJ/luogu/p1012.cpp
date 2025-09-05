#include <bits/stdc++.h>
using namespace std;
string num[25];
struct student {
    int number, chinese, math, eng;
    string name;
    string phone, birthday;
}a[110];

student b[100];

bool mycmp(string a, string b) {
    for (int i = 0; a[i] && b[i]; ++i) {
        if (a[i] > b[i]) return 1;
        else if (a[i] < b[i]) return 0;
    }
    return 0;
}

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].eng >> a[i].math;
    }
    return 0;
}

