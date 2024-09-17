#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dis[2510];
    bool fd[2510];
    int mp[2510][2510];
    int id[55][55];
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        memset(mp, 127, sizeof(mp));
        int n = grid.size();
        int m = grid[0].size();
        cout << n << m;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++i) {
                id[i][j] = (i-1)*m+j;
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int x = id[i][j];
                if (i < n) {
                    int y = id[i+1][j];
                    if (grid[i-1][j-1] == 0 && grid[i][j-1] == 0) mp[x][y] = mp[y][x] = 0;
                    else mp[x][y] = mp[y][x] = 1;
                }
                if (j < m) {
                    int y = id[i][j+1];
                    if (grid[i-1][j-1] == 0 && grid[i-1][j] == 0) mp[x][y] = mp[y][x] = 0;
                    else mp[x][y] = mp[y][x] = 1;
                }
            }
        }

        for (int i = 2; i <= m*n; ++i) dis[i] = mp[1][i];

        int minn;
        int pos;
        fd[1] = 1;
        for (int i = 1; i <= n; ++i) {
            minn = 0x3f3f3f3f;
            for (int j = 1; j <= n; ++j) {
                if (!fd[j] && dis[j] < minn) {
                    minn = dis[j];
                    pos = j;
                }
            }
            fd[pos] = 1;
            for (int j = 1; j <= n; ++j) {
                if (!fd[j] && dis[j] > dis[pos] + mp[pos][j])
                    dis[j] = dis[pos] + mp[pos][j];
            }
        }
        return dis[m*n] < health;
    }
};

int main() {
    Solution a;
    vector<vector<int>> grid = {{0,1,0,0,0},{0,1,0,1,0},{0,0,0,1,0}};
    cout << a.findSafeWalk(grid, 1);
    return 0;
}