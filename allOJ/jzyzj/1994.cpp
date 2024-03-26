/*#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
#define lowbit(o) (o&(-o))
#define ll long long
using namespace std;
ll c[51000][6];
ll n;
ll a[51000];
ll maxx;

void updata(ll id,ll i,ll val){
	while (i <= maxx){
		c[i][id] += val;
		i+=lowbit(i);
	}
}

ll findit(ll id,ll x){
	ll temp=0;
	while(x>0){
		temp+=c[x][id];
		x-=lowbit(x);
	}
	return temp;
}

void work(){
	memset(c,0,sizeof(c));
	for(int i=1;i<=n;++i){
		updata(1,a[i],1);
		for(int j=1;j<=4;++j){
			ll sum=findit(j,a[i]-1);
			updata(j+1,a[i],sum);
		}
	}
}

int main(){
	//freopen("a.txt","r",stdin);
	//freopen("b.txt","w",stdout);
	cin>>n;
	maxx=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if(a[i]>maxx) maxx=a[i];
	}
	work();
	cout<<findit(5,maxx)<<endl;
	//cout<<5 + lowbit(5)<<endl;
	return 0;
}
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n;int const maxn=51000;
ll c[6][maxn];
int a[maxn];
int maxx = 0;
inline int lowbit(int x)
{
	return x&(-x);
}
void add(int x,ll v,int s)
{
	while(x<=maxn){
		c[s][x]+=v;
		x+=lowbit(x);
	}
}
ll sum(int x,int s)
{
	ll res=0;
	while(x>0)
	{
		res+=c[s][x];
		x-=lowbit(x);
	}
	return res;
}
int main()
{
	freopen("a.1", "r", stdin);
	freopen("b.1", "w", stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		maxx = max(maxx, a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		add(a[i],1,1);
		add(a[i],sum(a[i]-1,1),2);
		add(a[i],sum(a[i]-1,2),3);
		add(a[i],sum(a[i]-1,3),4);
		add(a[i],sum(a[i]-1,4),5);
	}
	//ll maxx=0;
	/*for(int i=1;i<=n;i++)
	{
		maxx=max(maxx,sum(a[i],5));
	}*/

	cout << sum(maxx, 5) <<endl;
	return 0;
}


