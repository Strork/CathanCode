#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> mp;
vector<string> cheater;
bool hunter[100005], cheat[100005];
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        string name;
        cin >> name;
        mp[name] = i;
    }
    hunter[1] = 1;
    for (int i = 1; i <= m; ++i) {
        string a, b;
        cin >> a >> b >> b;
        int x = mp[a], y = mp[b];
        if (hunter[x] == 0 && cheat[x] == 0) {
            cheater.push_back(a);
            cheat[x] = 1;
        } else if (hunter[x] == 1) { // 他是猎人的情况下碰别人，猎人状态取消
            hunter[x] = 0;
        }
        hunter[y] = 1; // y 变成猎人
    }
    sort(cheater.begin(), cheater.end());
    cout << cheater.size() << endl;
    for (int i = 0; i < cheater.size(); ++i) {
        cout << cheater[i] << ' ';
    }
    return 0;
}