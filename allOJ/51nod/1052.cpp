#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f[5050];
ll a[5050];
ll pre[5050];
ll ans;
int n,m;

int main()
{
	memset(f,128,sizeof(f));
	//cout<<f[0]<<endl;
	memset(pre,0,sizeof(pre));
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; ++i)
		scanf("%lld",&a[i]);
	//cout<<a[3]<<' '<<a[4]<<endl;
	for(int k = 1; k <= m; ++k)
	{
		ans = f[0];
		f[1] = a[1];
		pre[0] = ans;
		ans = max(ans,f[1]);
		for(int i = 2; i <= n; i++)
		{
			f[i] = max(pre[i-1],f[i-1]) + a[i];
			pre[i-1] = ans;
			ans = max(ans,f[i]);
		}
		pre[n] = ans;
	}
	printf("%lld\n",pre[n]);
	return 0;
}

