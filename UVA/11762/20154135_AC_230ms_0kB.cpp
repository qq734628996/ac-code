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
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const int INF = 0x3f3f3f3f, MOD = 100000007;
const int MAXN = 1e6+9, MAXM = 1e4+5;

int vis[MAXN],prime[MAXN],tot;
void getPrime(int n)
{
    FOR(i,2,n) {
        if (!vis[i]) prime[tot++]=i;
        REP(j,tot) {
            if (i*prime[j]>n) break;
            vis[i*prime[j]]=1;
            if (i%prime[j]==0) break;
        }
    }
}
double f[MAXN];
double dp(int x)
{
    if (x==1) return 0.0;
    if (vis[x]) return f[x];
    vis[x]=1;
    double& ans=f[x];
    int g=0, p=0;
    ans=0;
    for (int i=0; i<tot && prime[i]<=x; i++) {
        p++;
        if (x%prime[i]==0) {
            g++;
            ans+=dp(x/prime[i]);
        }
    }
    ans=(ans+p)/g;
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    getPrime(MAXN-1);
    memset(vis,0,sizeof(vis));
    int T; scanf("%d", &T);
    FOR(kase,1,T) {
        int x; scanf("%d", &x);
        printf("Case %d: %.7f\n", kase,dp(x));
    }

    return 0;
}




































