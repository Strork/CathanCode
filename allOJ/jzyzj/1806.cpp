#include<bits/stdc++.h>
using namespace std;
int st;
int ed;
int n;
int m;
char a[10100];

void solution() {
	int T = 5;
	while (T--) {
		int j = m;
		while (j >= 1 && n - m + j == a[j]) --j;
		if (j >= 1) {
			++a[j];
			for(int i = j + 1; i <= m; ++i) a[i] = a[i - 1] + 1;
			for(int i = 1; i <= m; ++i) printf("%c", a[i] + 'a' - 1 + st - 1);
			cout<<endl;
		}
	}
}

int main() {
	cin>>st>>ed;
	n = ed - st + 1;
	cin>>m;
	for (int i = 1; i <= m; ++i) {
		char ch;
		cin>>ch;
		a[i] = ch - 'a' + 1 - st + 1;
	}
	solution();
	return 0;
}

