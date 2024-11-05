#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    int a = 0;
    int sep = 0;
    for (int i = 0; i <= 10; ++i) {
        if (isdigit(str[i])) {
            a += (++sep) * (str[i] - '0');
        }
    }
    if (a % 11 == 10 && str[12] == 'X') cout << "Right" << endl;
    else if (a % 11 == str[12] - '0') cout << "Right" << endl;
    else {
        for (int i = 0; i <= 11; ++i) printf("%c", str[i]);
        if (a % 11 != 10) printf("%d\n", a % 11);
        else printf("X\n");
    }
    return 0;
}