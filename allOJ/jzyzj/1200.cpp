#include<bits/stdc++.h>
#define INF 2100000000
using namespace std;
int n;
int m1, m2;
int p1[10010];
int p2[10010];
int c1[10010];
int c2[10010];
int a[10010];
int t1 = 0;
int t2 = 0;
int ans = INF;
int maxx = -INF;

void solution() {
	int temp = m1;
	for (int i = 2;;) {
		if (temp % i == 0) {
			p1[++t1] = i;
			c1[t1] = 0;
			while (temp % i == 0) {
				temp /= i;
				++c1[t1];
			}
		}
		else ++i;
		if (i * i > temp && temp > 1) {
			p1[++t1] = temp;
			c1[t1] = 1;
			break;
		}
		if (i * i > temp && temp <= 1) break;
	}
	for (int j = 1; j <= n; ++j) {
		memset(p2, 0, sizeof(p2));
		temp = a[j];
		t2 = 0;
		for (int i = 2;;) {
			if (temp % i == 0) {
				p2[++t2] = i;
				c2[t2] = 0;
				while (temp % i == 0) {
					temp /= i;
					++c2[t2];
				}
			}
			else ++i;
			if (i * i > temp && temp > 1) {
				p2[++t2] = temp;
				c2[t2] = 1;
				break;
			}
			if (i * i > temp && temp <= 1) break;
		}
		maxx = -INF;
		for (int i = 1, k = 1; i <= t1 && k <= t2;) {
			if (p1[i] != p2[k]) {
				++k;
				continue;
			}
			temp = c1[i] * m2 / c2[k];
			if (c1[i] * m2 % c2[k] != 0) ++temp;
			if (temp > maxx) maxx = temp;
			if (i == t1) {
				if(maxx < ans) ans = maxx;
			}
			++i;++k;
		}
	}
	if(ans == INF) {
		printf("-1\n");
		return;
	}
	printf("%d\n", ans);
}

int main() {
	//freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	scanf("%d", &n);
	scanf("%d%d", &m1, &m2);
	if (m1 == 1 && n >= 1) {
		cout<<0<<endl;
		return 0;
	}
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	solution();
	return 0;
}
