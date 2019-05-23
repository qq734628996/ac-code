#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n-1) printf("%d ", A[i]); printf("%d\n", A[n-1]); }
#define SHOW2(A,m,n) { REP(i,m) { REP(j,n-1) printf("%d ", A[i][j]); printf("%d\n", A[i][n-1]); } }
#define pb push_back
#define fi first
#define se second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)((x).size())
typedef long long LL;
typedef pair<int, int> pii;
const int MAXN = 1e5+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n,r,c,a[22],sum[1<<16],vis[1<<16][123],d[1<<16][123],kase;
int bits(int x) { return x ? bits(x/2)+(x&1):0; }
int dp(int S, int x)
{
    int& ans=d[S][x];
    if (vis[S][x]==kase) return ans;
    vis[S][x]=kase;
    if (bits(S)==1) return ans=1;
    int y=sum[S]/x;
    for (int S0=(S-1)&S; S0; S0=(S0-1)&S) {
        int S1=S^S0;
        if (sum[S0]%x==0 && dp(S0,min(x,sum[S0]/x)) && dp(S1,min(x,sum[S1]/x))
         || sum[S0]%y==0 && dp(S0,min(y,sum[S0]/y)) && dp(S1,min(y,sum[S1]/y)))
            return ans=1;
    }
    return ans=0;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n)==1 && n) {
        kase++;
        scanf("%d%d", &r,&c);
        REP(i,n) scanf("%d", &a[i]);
        memset(sum,0,sizeof(sum));
        REP(S,(1<<n))REP(i,n)if (S&(1<<i)) sum[S]+=a[i];
        int tot=(1<<n)-1;
        int ans=0;
        if (sum[tot]==r*c && sum[tot]%r==0) ans=dp(tot,min(r,c));
        printf("Case %d: %s\n", kase,ans ? "Yes":"No");
    }

    return 0;
}










































