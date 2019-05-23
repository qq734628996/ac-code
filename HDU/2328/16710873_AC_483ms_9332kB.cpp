#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <ctime>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define calm (l+r)>>1
const int INF = 2139062143;

const int maxn=1000010;
struct SA{
    #define F(x) ((x)/3+((x)%3==1?0:tb))
    #define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
    int wa[maxn],wb[maxn],wv[maxn],ws[maxn];
    int rank[maxn],height[maxn];
    int c0(int *r,int a,int b)
    {return r[a]==r[b]&&r[a+1]==r[b+1]&&r[a+2]==r[b+2];}
    int c12(int k,int *r,int a,int b){
        if(k==2) return (r[a]<r[b])||(r[a]==r[b]&&c12(1,r,a+1,b+1));
        else return (r[a]<r[b])||(r[a]==r[b]&&wv[a+1]<wv[b+1]);
    }
    void sort(int *r,int *a,int *b,int n,int m){
         int i;
         for(i=0;i<n;i++) wv[i]=r[a[i]];
         for(i=0;i<m;i++) ws[i]=0;
         for(i=0;i<n;i++) ws[wv[i]]++;
         for(i=1;i<m;i++) ws[i]+=ws[i-1];
         for(i=n-1;i>=0;i--) b[--ws[wv[i]]]=a[i];
         return;
    }
    void dc3(int *r,int *sa,int n,int m){
         int i,j,*rn=r+n,*san=sa+n,ta=0,tb=(n+1)/3,tbc=0,p;
         r[n]=r[n+1]=0;
         for(i=0;i<n;i++) if(i%3!=0) wa[tbc++]=i;
         sort(r+2,wa,wb,tbc,m);
         sort(r+1,wb,wa,tbc,m);
         sort(r,wa,wb,tbc,m);
         for(p=1,rn[F(wb[0])]=0,i=1;i<tbc;i++)
         rn[F(wb[i])]=c0(r,wb[i-1],wb[i])?p-1:p++;
         if(p<tbc) dc3(rn,san,tbc,p);
         else for(i=0;i<tbc;i++) san[rn[i]]=i;
         for(i=0;i<tbc;i++) if(san[i]<tb) wb[ta++]=san[i]*3;
         if(n%3==1) wb[ta++]=n-1;
         sort(r,wb,wa,ta,m);
         for(i=0;i<tbc;i++) wv[wb[i]=G(san[i])]=i;
         for(i=0,j=0,p=0;i<ta && j<tbc;p++)
         sa[p]=c12(wb[j]%3,r,wa[i],wb[j])?wa[i++]:wb[j++];
         for(;i<ta;p++) sa[p]=wa[i++];
         for(;j<tbc;p++) sa[p]=wb[j++];
         return;
    }
    void calheight(int *r,int *sa,int n){
         int i,j,k=0;
         for(i=1;i<=n;i++) rank[sa[i]]=i;
         for(i=0;i<n;height[rank[i++]]=k)
         for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
         return;
    }
}rst;
char str[maxn];
int r[maxn],sa[maxn];
int n;
int id[maxn];
bool vis[4040];
int cal(int x,int len){
    memset(vis,false,sizeof vis);
    int cnt=0;
    for(int i=2;i<=len;i++){
        int t=rst.height[i];
        if(t>=x){
            int num=id[sa[i]];
            if(num&&!vis[num]){
                vis[num]=true;cnt++;
            }
            num=id[sa[i-1]];
            if(num&&!vis[num]){
                vis[num]=true;cnt++;
            }
        }
        else{
            if(cnt==n)return sa[i-1];
            cnt=0;
            memset(vis,false,sizeof vis);
        }
    }
    if(cnt==n)return sa[len-1];
    return -1;
}
int main(){
    //freopen("D://input.txt","r",stdin);
    while(scanf("%d",&n)!=EOF&&n){
        int len=0,now;
        memset(id,0,sizeof id);
        int mn=INF;
        for(int i=1;i<=n;i++,len++){
            scanf("%s",str+len);
            now=strlen(str+len);
            mn=min(mn,now);
            len+=now;
            str[len]='#';
        }
        int idx=1;
        for(int i=0;i<len;i++){
            if(str[i]=='#')idx++;
            else id[i]=idx;
        }
        str[--len]='\0';
        for(int i=0;i<len;i++)r[i]=str[i];
        r[len]=0;
        rst.dc3(r,sa,len+1,128);
        rst.calheight(r,sa,len);
        int ans=-1,tot=-1;
        int l=1,r=mn;
        while(l<=r){
            int mid=(l+r)>>1;
            int x=cal(mid,len);
            if(x!=-1){
                ans=x;tot=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        if(ans==-1){
            printf("IDENTITY LOST\n");
        }
        else{
            str[ans+tot]='\0';
            printf("%s\n",str+ans);
        }
    }
    return 0;
}
