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
const int INF = 0x3f3f3f3f, MOD = 1000000007;
const double PI = acos(-1), EPS = 1e-15;
const int MAXN = 1e6+9, MAXM = 3e3+9;

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
LL a,b;
vector<pll> e;
void gete(LL x)
{
    e.clear();
    REP(i,tot) {
        if ((LL)prime[i]*prime[i]>x || x==1) break;
        if (x%prime[i]==0) {
            int cnt=0;
            while (x%prime[i]==0) {
                cnt++;
                x/=prime[i];
            }
            e.pb({prime[i],cnt});
        }
    }
    if (x!=1) e.pb({x,1});
}
LL dfs(int i, LL now)
{
    if (i==SZ(e)) return now>=b && a/now>=b && now<a/now;
    LL p=e[i].fi, cnt=e[i].se, t=1, ans=0;
    FOR(j,0,cnt) {
        ans+=dfs(i+1,now*t);
        t*=p;
    }
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    getPrime(MAXN-1);
    int T; scanf("%d", &T);
    FOR(kase,1,T) {
        scanf("%lld%lld", &a,&b);
        gete(a);
        printf("Case %d: %lld\n", kase,dfs(0,1));
    }

    return 0;
}































