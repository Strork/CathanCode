#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int n;
ll a[3000100];
ll b[3000100];
int c[40];
int tail = 0;
int id;
int k;

void solution() {
	id = 1;
	for (int i = 1; i <= tail; ++i) cout<<a[i]<<' '<<b[i]<<endl;
	for (int i = 2; i <= tail; ++i) {
		ll temp = 0;
		if (b[id] == b[i]) {
			cout<<"--------"<<endl;
			if (a[i] > a[id]) id = i;
			continue;
		}
		else if(b[id] < b[i]) {
			temp = a[i];
			k = b[i];
			while (b[id] < k) {
				k /= 2;
				temp *= temp;
				cout<<temp<<endl;
			}
			if (temp > a[id]) id = i;
		}
		else if(b[id] > b[i]) {
			temp = a[id];
			k = b[id];
			while (k > b[i]) {
				k /= 2;
				temp *= temp;
				cout<<temp<<endl;
			}
			if (temp < a[i]) id = i;
		}
	}
	int ans = a[id];
	for (int i = 2; i <= b[id]; ++i)
		ans = 1LL * ans * ans % mod;
	printf("%d\n", ans);
}

int main () {
	cin>>n;
	if (n <= 3) {
		printf("1\n");
		return 0;
	}
	c[1] = 2;
	for (int i = 2; i <= 30; ++i) c[i] = c[i - 1] * 2;
	for (int i = 2; i * i <= n; ++i) {
		//cout<<i<<endl;
		int temp = n;
		k = 0;
		while (temp) {
			k += temp / i;
			temp /= i;
		}
		if (k & 1) continue;
		else {
			cout<<k<<endl;
			//bool flag = 0;
			for (int j = 1; j <= 30; ++j) if (k < c[j]) { k = c[j - 1]; break; }
			//if (!flag) continue;
			a[++tail] = i;
			//cout<<a[tail]<<endl;
			b[tail] = k;
		}
	}
	solution();
	return 0;
}
