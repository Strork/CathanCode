#include <bits/stdc++.h>
using namespace std;
string star = "************************";

int main() {
    int a;
    cin >> a;
    
    int cnt = 0;
    int b = a;
    while (b) {
        cnt++;
        b/=10;
    }
    while (cnt--) star += '*';
	cout << star << endl;
    printf("*Welcome,ContestantNo.%d!*\n", a);
    cout << star << endl;
    return 0;
}