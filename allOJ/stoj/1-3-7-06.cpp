#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ed = s.size() - 2;
    if (s.find("er", ed) != string::npos) {
        s.erase(ed);
    } else if (s.find("ly", ed) != string::npos) {
        s.erase(ed);
    } else {
        ed -= 1;
        if (s.find("ing", ed) != string::npos) {
            s.erase(ed);
        }
    }
    cout << s << endl;
    return 0;
}