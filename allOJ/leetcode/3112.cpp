#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

typedef pair<int, int> pii;
int dis[50010];
bool vis[50010];
struct qwq{
    int y, v, nt;
}e[200100];
int len = 0;
int lin[50010];
vector<int> ans;

    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        priority_queue<pii, vector<pii>, greater<pii>> q;
        for (auto i : edges) {
            e[++len].nt = lin[i[0]];
            lin[i[0]] = len;
            e[len].y = i[1];
            e[len].v = i[2];
            e[++len].nt = lin[i[1]];
            lin[i[1]] = len;
            e[len].y = i[0];
            e[len].v = i[2];
        }
        memset(dis, 0x3f, sizeof(dis));
        dis[0] = 0;
        q.push(make_pair(0, 0));
        while (!q.empty()) {
            pii tmp = q.top();
            q.pop();
            int x = tmp.second;
            if (vis[x]) continue;
            vis[x] = 1;
            for (int i = lin[x]; i; i = e[i].nt) {
                int y = e[i].y;
                if (dis[x] + e[i].v < dis[y] && dis[x] + e[i].v < disappear[y]) {
                    dis[y] = dis[x] + e[i].v;
                    q.push(make_pair(dis[y], y));
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) dis[i] = -1;
            ans.push_back(dis[i]);
        }
        return ans;
    }
};