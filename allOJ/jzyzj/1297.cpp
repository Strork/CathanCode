#include<bits/stdc++.h>
using namespace std;
struct qaq
{
	int tim,x,val;
}a[1010];
int w,h;
int n = 0;
int f[1010];
int r[1010];
int ans[1100];
int maxtime = 0;

bool mycmp(qaq x,qaq y)
{
	return x.tim < y.tim;
}

void output(int x,int y)
{
	if(r[x] != -1) output(r[x],x);
	int tim = a[y].tim - a[x].tim;
	int dis = a[y].x - a[x].x;
	//cout<<tim<<"---------"<<endl;
	while(tim--)
	{
		if(dis <= -2)
		{
			cout<<-2<<endl;
			dis += 2;
		}
		else if(dis == -1)
		{
			cout<<-1<<endl;
			dis += 1;
		}
		else if(dis >= 2) 
		{
			cout<<2<<endl;
			dis -= 2;
		}
		else if(dis == 1)
		{
			cout<<1<<endl;
			dis -= 1;
		}
		else cout<<0<<endl;
	}
}

void solution()
{
	sort(a+1,a+1+n,mycmp);
	for(int i=1;i<=n;i++)cout<<a[i].tim<<"--"<<a[i].x<<"--"<<a[i].val<<endl;
	memset(r,-1,sizeof(r));
	for(int i = 1; i <= n; ++i)
	{
		int dis;
		int tim;
		for(int j = 0; j < i; j++)
		{
			dis = abs(a[j].x - a[i].x);
			tim = a[i].tim - a[j].tim;
			if(f[j] + a[i].val > f[i] && tim * 2 >= dis)
			{
				r[i] = j;
				f[i] = f[j] + a[i].val;
			}
		}
	}
	cout<<f[n]<<endl;
	//for(int i = 1; i <= n; i++) cout<<f[i]<<endl;
	output(r[n],n);
}

int main()
{
	freopen("a.txt","r",stdin);
	freopen("b.txt","w",stdout);
	cin>>w>>h;
	int t,x,v,val;
	while(~scanf("%d",&t))
	{
		scanf("%d%d%d",&x,&v,&val); 
		//if((h - 1)  % v != 0) continue;
		//else
		//{	
			a[++n].tim = t + (h - 1) / v;
			a[n].val = val;
			a[n].x = x;
			if(a[n].tim > maxtime) maxtime = a[n].tim;
		//}
	}
	a[0].tim = 0;
	a[0].x = (w + 1) / 2;
	solution();
	return 0;
}

