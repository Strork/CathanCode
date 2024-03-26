#include<bits/stdc++.h>
using namespace std;
int l,r,a;

int main(){
	int ans = 0;
	cin>>l>>r>>a;
	ans += min(l,r);
	int lst = max(l,r) - min(l,r);
	if(a >= lst){
		ans += lst;
		a -= lst;
		ans += a/2;
	}
	else ans += a;
	printf("%d\n",ans*2);
	return 0;
}
