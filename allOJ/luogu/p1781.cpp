// #include <bits/stdc++.h>
// using namespace std;
// int num[25];
// string ticket[25];
// int n;

// bool big(string a, string b) {
//     if (a.size() > b.size()) return true;
//     if (a.size() == b.size() && a > b) return true;
//     return false;
// }

// int main() {
//     cin >> n;
//     for (int i = 1; i <= n; ++i) {
//         cin >> ticket[i];
//         num[i] = i;
//     }
//     for (int i = 1; i < n; ++i) {
//         for (int j = 1; j <= n-i; ++j) {
//             if (big(ticket[j], ticket[j+1])) {
//                 swap(ticket[j], ticket[j+1]);
//                 swap(num[j], num[j+1]);
//             }
//         }
//     }
//     cout << num[n] << endl;
//     cout << ticket[n] << endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int n;
string ticket[25];
int id;

bool cmp(string a, string b) {
    if (a.size() > b.size()) return true;
    else if (a.size() == b.size()) {
        if (a > b) return true;
    }
    return false;
}

int main() {
    cin >> n;
    id = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> ticket[i];
        if (cmp(ticket[i], ticket[id])) {
            id = i;
        }
    }
    cout << id << endl;
    cout << ticket[id] << endl;
    return 0;
}