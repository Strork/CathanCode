#include<bits/stdc++.h>
using namespace std;
int n;
struct qaq {
	int p[10010];
	int tail;
	int v;
	int q[10010];
}a[110];
int ans = 1;
int cnt = 0;
int sum = 0;
bool f[1000010];

void solution() {
	for (int i = 1; i <= n; ++i) {
		int temp = a[i].v;
		int j = 2;
		while (temp > 1) {
			if (temp % j == 0) {
				a[i].p[++a[i].tail] = j;
				a[i].q[a[i].tail] = 0;
				while (temp % j == 0) ++a[i].q[a[i].tail], temp /= j;
			}
			else ++j;
			if (j * j > temp && temp > 1) {
				a[i].p[++a[i].tail] = temp;
				a[i].q[a[i].tail] = 1;
				break;
			}
		}
	}
	//cout<<"WQEQWEWQEWQEWQ"<<endl;
	cnt = 0;
	for (int i = 1; i <= n; ++i) {
		//cout<<i<<"---------"<<endl;
		for (int j = 1; j <= a[i].tail; ++j) {
			//cout<<a[i].p[j]<<'^'<<a[i].q[j]<<' ';
			if (f[a[i].p[j]]) continue;
			//cout<<a[i].p[j]<<'^'<<a[i].q[j]<<' ';
			f[a[i].p[j]] = 1;
			sum = 0;
			//sum += a[i].q[j];
			for (int x = 1; x <= n; ++x) {
				for (int y = 1; y <= a[x].tail; ++y) {
					if (a[x].p[y] == a[i].p[j]) {
						sum += a[x].q[y];
						break;
					}
				}
			}
			//cout<<a[i].p[j]<<' '<<sum<<endl;;
			if (sum / n) {
				//cout<<sum<<endl;
				int temp = sum / n;
				//cout<<temp<<endl;
				bool flag = 0;
				for (int x = 1; x <= n; ++x) {
					flag = 0;
					for (int y = 1; y <= a[x].tail; ++y) {
						if (a[x].p[y] == a[i].p[j]) {
							flag = 1;
							if (a[x].q[y] < temp) {
								cnt += temp - a[x].q[y];
							}
							break;
						}
					}
					if (!flag) cnt += temp;
				}
				for (int o = 1; o <= temp; o++)
					ans *= a[i].p[j];
			}
			//f[a[i].p[j]] = 1;
		}
	}
	printf("%d %d\n", ans, cnt);
}

int main() {
	//freopen("b.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i].v);
	}
	solution();
	return 0;
}
