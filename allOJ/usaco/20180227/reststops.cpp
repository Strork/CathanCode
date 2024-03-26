#include<bits/stdc++.h>
#define ll long long
using namespace std;
int L,n;
int fj,bs;
struct qaq
{
	int x,v;
}a[100100];

int read()
{
	int k = 0;
	char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) 
	{
		k = k * 10 + ch - '0';
		ch = getchar();
	}
	return k;
}

bool mycmp(qaq x,qaq y)
{
	if(x.v == y.v) return x.x > y.x;
	else return x.v > y.v;
}

void solution()
{
	sort(a+1,a+1+n,mycmp);
	int p = 0;
	ll ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		if(a[i].x > p)
		{	
			ll t = (ll)(fj - bs) * (ll)(a[i].x - p);
			ans += t * a[i].v;
			p = a[i].x;
			//cout<<p<<endl;
		}
		else continue;
		//cout<<a[i].x<<' '<<a[i].v<<endl;
	}
	printf("%lld\n",ans);
}

int main()
{
	freopen("reststops.in","r",stdin);
	freopen("reststops.out","w",stdout);
	L = read();
	n = read();
	fj = read();
	bs = read();
	for(int i = 1; i <= n; ++i)
	{
		a[i].x = read();
		a[i].v = read();
	}
	solution();
	return 0;
}

