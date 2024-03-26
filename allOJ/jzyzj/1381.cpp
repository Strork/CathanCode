#include<bits/stdc++.h>
#define up(i,x,y) for(int i = x; i <= y; ++i)
using namespace std;
bool f = 1;
int a[10][10];
int id[10][10] = {
	0,0,0,0,0,0,0,0,0,0,
	0,1,1,1,2,2,2,3,3,3,
	0,1,1,1,2,2,2,3,3,3,
	0,1,1,1,2,2,2,3,3,3,
	0,4,4,4,5,5,5,6,6,6,
	0,4,4,4,5,5,5,6,6,6,
	0,4,4,4,5,5,5,6,6,6,
	0,7,7,7,8,8,8,9,9,9,
	0,7,7,7,8,8,8,9,9,9,
	0,7,7,7,8,8,8,9,9,9
};
int flag[10];
int n;

int main() {
	scanf("%d", &n);
	while (n--) {
		f = 1;
		memset(flag, 0, sizeof(flag));

		up(i, 1, 9) {
			up(j, 1, 9) {
				scanf("%d", &a[i][j]);
				flag[id[i][j]] |= (1 << a[i][j]);
			}
		}

		up(i, 1, 9) {
			if (flag[i] != (1 << 10) - 2) {
				f = 0;
				break;
			}

			flag[0] = 0;
			up(j, 1, 9) 
				flag[0] = flag[0] | (1 << a[i][j]);
			if (flag[0] != (1 << 10) - 2) {
				f = 0;
				break;
			}

			flag[0] = 0;
			up(j, 1, 9)
				flag[0] = flag[0] | (1 << a[j][i]);
			if (flag[0] != (1 << 10) - 2) {
				f = 0;
				break;
			}
		}
		if (f) printf("Right\n");
		else printf("Wrong\n");
	}
	return 0;
}
