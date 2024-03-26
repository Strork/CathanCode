#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100100];
int b[100100];

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; ++i) scanf("%d",&a[i]);
	for(int i = 1; i <= m; ++i) scanf("%d",&b[i]);
	int ia = 0, ib = 0;
	int sa = 0;
	int sb = 0;
	int ans = 0;
	while(ia <= n && ib <= m){
		if(sa == 0 && sb == 0) sa += a[++ia], sb += b[++ib];
		if(sa == sb){
			++ans;
			sa = 0;
			sb = 0;
		}
		if(ia == n && ib == m) break;
		else if(sa < sb){
			sa += a[++ia];
		}
		else if(sa > sb){
			sb += b[++ib];
		}
	}
	printf("%d\n",ans);
	return 0;
}
