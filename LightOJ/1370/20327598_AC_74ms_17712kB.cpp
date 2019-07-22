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

int vis[MAXN],prime[MAXN],phi[MAXN],tot;
void getphi(int n)
{
    phi[1]=1;
    FOR(i,2,n) {
        if (!vis[i]) prime[tot++]=i, phi[i]=i-1;
        REP(j,tot) {
            if (i*prime[j]>n) break;
            vis[i*prime[j]]=1;
            if (i%prime[j]==0) {
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            } else phi[i*prime[j]]=phi[i]*(prime[j]-1);
        }
    }
}
int f[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    getphi(MAXN-1);
    memset(f,INF,sizeof(f));
    ROF(i,2,MAXN-1) f[phi[i]]=i;
    ROF(i,1,MAXN-2) f[i]=min(f[i],f[i+1]);
    int T; scanf("%d", &T);
    FOR(kase,1,T) {
        int n; scanf("%d", &n);
        LL ans=0;
        REP(i,n) {
            int x; scanf("%d", &x);
            ans+=f[x];
        }
        printf("Case %d: %lld Xukha\n", kase,ans);
    }

    return 0;
}
































