#include<bits/stdc++.h>
using namespace std;
const int N=1e5+19;
priority_queue<int, vector<int>, greater<int>> q;
vector<int> a[N];
int T,n,m,x,y;
int rd[N],ans[N],now,cnt;
void f(){
    now = 0;
    cnt = 0;
	while(q.size()){
		int t=q.top();
		q.pop();
		ans[++now]=t;
		cnt++;
		for(auto y:a[t]){
			rd[y]--;
			if(rd[y]==0)q.push(y);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>m;
        memset(rd, 0, sizeof(rd));
        while (q.size()) q.pop();
		for(int i=1;i<=m;i++){
			cin>>x>>y;
			a[x].push_back(y);
			rd[y]++;
		}
		for(int i=1;i<=n;i++){
			if(rd[i]==0){
				q.push(i);
			}
		}
		f();
		if(now!=n){
			cout<<now;
			puts("Impossible!");
		}else{
			for(int i=1;i<=n;i++){
				cout<<ans[i]<<' ';
			}
			cout<<endl;
		}
	}
	return 0;
}