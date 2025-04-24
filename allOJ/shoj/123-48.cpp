#include<bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
string s;
int x, y, p;

int main() {
    cin >> s;
    for (auto i : s) {
        if (i == 'F') x += dx[p], y += dy[p];
        else if (i == 'B') x -= dx[p], y -= dy[p];
        else if (i == 'R') ++p;
        else if (i == 'L') --p;
        p = (p+4)%4;
    }
    cout << x << ' ' << y << endl;
    return 0;
}
