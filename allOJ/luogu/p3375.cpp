#include <bits/stdc++.h>
using namespace std;
int pi[2000100];
int ls[2000100];
bool output[2000199];
int n;
string s1, s2;
string str;

int main() {
    cin >> s1 >> s2;
    str = s2 + "*" + s1;
    for (auto i = 1; i < str.size(); ++i) {
        ls[i] = ls[i-1];
        int len = pi[i-1];
        while (len != 0 && str[i] != str[len]) {
            len = pi[len-1];
        }
        if (str[i] == str[len]) pi[i] = len + 1;
        if (pi[i] == s2.length()) {

        }
    }
    
    return 0;
}
