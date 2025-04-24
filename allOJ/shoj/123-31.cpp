#include<bits/stdc++.h>
using namespace std;
int n;
int money[11];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &money[1]);
        if (money[1] == 5) {
            ++money[0];
            ++money[5];
        }
        else if (money[1] == 10) {
            if (money[5] >= 1) {
                ++money[0];
                --money[5];
                ++money[10];
            }
        }
        else if (money[1] == 20) {
            if (money[10] >= 1 && money[5] >= 1) {
                ++money[0];
                --money[10];
                --money[5];
            }
            else if (money[5] >= 3) {
                ++money[0];
                money[5] -= 3;
            }
        }
    }
    cout << money[0] << endl;
    return 0;
}
