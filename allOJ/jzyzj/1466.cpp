#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
const int maxn=600010;
int n,m,q;
int xx[maxn]={},yy[maxn]={};
int num[maxn]={},z[maxn]={};
int lag[maxn]={};
int t[maxn]={},mx;
vector<int>id[maxn];
vector<int>val[maxn];
vector<long long >shu[maxn];
char buf[1<<15],*fs,*ft;
inline char getc(){return (fs==ft&&(ft=(fs=buf)+fread(buf,1,1<<15,stdin),fs==ft))?0:*fs++;}
inline int read(){
int x=0,f=1;  char ch=getc();
while(!isdigit(ch))  {if(ch=='-')  f=-1;  ch=getc();}
while(isdigit(ch))  {x=x*10+ch-'0';  ch=getc();}
return x*f;
}
inline void add(int x,int v){
	while(x<=mx){
		t[x]+=v;
		x+=(x&-x);
	}
}
inline int getit(int x){
	int tsn=0;
	while(x){
		tsn+=t[x];
		x-=(x&-x);
	}return tsn;
}
inline int Find(int x){
	int l=0,r=mx,mid;
	while(l<r){
		mid=(l+r)/2;
		if(getit(mid)<x)l=mid+1;
		else r=mid;
	}
	return l;
}
int main(){
	n=read();m=read();q=read();
	mx=max(n,m)+q;
	for(int i=1;i<=q;i++){
		xx[i]=read();yy[i]=read();
		if(yy[i]!=m){
			val[xx[i]].push_back(yy[i]);
			id[xx[i]].push_back(i);
		}
		else
			z[i]=1;
	}
	for(int i=1;i<=mx;i++)add(i,1);
	for(int i=1;i<=n;i++){
		int siz=id[i].size();
		for(int j=0;j<siz;j++){
			num[id[i][j]]=Find(val[i][j]);
			add(num[id[i][j]],-1);
		}
		for(int j=0;j<siz;j++)add(num[id[i][j]],1);
	}
	long long ans;
	for(int i=0;i<=n;i++)shu[0].push_back((long long)i*m);
	lag[0]=m;
	for(int i=1;i<=q;i++){
		if(z[i]){
			ans=shu[0][Find(xx[i])];
			add(Find(xx[i]),-1);
		}
		else if(num[i]<=m+lag[xx[i]]-1){
			ans=num[i]<m?(long long)(xx[i]-1)*m+num[i]:shu[xx[i]][num[i]-m];
			shu[xx[i]].push_back(shu[0][Find(xx[i])]);
			lag[xx[i]]++;
			add(Find(xx[i]),-1);
		}
		else{
			ans=shu[0][Find(num[i]-m-lag[xx[i]]+xx[i])];
			add(Find(num[i]-m-lag[xx[i]]+xx[i]),-1);
		}
		shu[0].push_back(ans);lag[0]++;
		printf("%lld\n",ans);
	}
	return 0;
}


