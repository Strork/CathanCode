#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int n,m,k,ans,cnt;
double sum;
int a[N][3],dis[N],pre[N];
struct E{
    int x,y;
    double w;
}p[N];
int cmp(E ea,E eb){
    return ea.w<eb.w;
}
int find(int x){
    return x==pre[x]?x:(pre[x]=find(pre[x]));
}
double cal(int x1,int y1,int x2,int y2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}
void kruskal(){
    cnt=n;
    for(int i=1;i<=k;i++){
        if(cnt==1) break;
        int s1=find(p[i].x),s2=find(p[i].y);
        if(s1!=s2){
            pre[s1]=s2;
            cnt--;
            sum+=p[i].w;
        }
    }
}
int main(){
    cin>>m;
    for(int i=1;i<=m;i++) cin>>dis[i];
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2];
    for(int i=1;i<=n;i++) pre[i]=i;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j){
                k++;
                p[k].x=i;
                p[k].y=j;
                p[k].w=cal(a[i][1],a[i][2],a[j][1],a[j][2]);
            }
        }
    }
    sort(p+1,p+k+1,cmp);
    kruskal();
    for(int i=1;i<=m;i++){
        if(sum<=dis[i])
            ans++;
    }
    cout<<ans;

    return 0;
}