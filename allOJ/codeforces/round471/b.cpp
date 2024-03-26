#include<bits/stdc++.h>
using namespace std;
char s[100100];
int f[1001];
int n = 0;
int cnt = 0;
int q[1001];
int tail = 0;

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; ++i) {
		++f[s[i]];
	}
	for (int i = 1; i <= 260; ++i) {
		if (f[i]) {
			q[++cnt] = i;
		}
	}
	if (cnt <= 1) {
		cout<<"No"<<endl;
		return 0;
	}
	else if (cnt == 2) {
		for (int i = 1; i <= cnt; ++i) {
			if (f[q[i]] <= 1) {
				cout<<"No"<<endl;
				return 0;
			}
		}
		cout<<"Yes"<<endl;
	}
	else if (cnt == 3) {
		for (int i = 1; i <= cnt; ++i) {
			if (f[q[i]] >= 2) {
				cout<<"Yes"<<endl;
				return 0;
			}
		}
		cout<<"No"<<endl;
	}
	else if (cnt == 4) {
		cout<<"Yes"<<endl;
	}
	else cout<<"No"<<endl;
	return 0;
}
