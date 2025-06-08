#include <bits/stdc++.h>
using namespace std;
int tree[1100000];
int T;

int main() {
    cin >> T;
    while (T--) {
        int depth, ball;
        memset(tree, 0, sizeof(tree));
        scanf("%d %d", &depth, &ball);
        int id;
        for (int i = 1; i <= ball; ++i) {
            id = 1;
            for (int j = 1; j < depth; ++j) {
                if (tree[id] == 0) {
                    tree[id] = 1;
                    id = id<<1;
                } else {
                    tree[id] = 0;
                    id = (id<<1)+1;
                }
            }
        }
        printf("%d\n", id);
    }
    cin >> T;
    return 0;
}