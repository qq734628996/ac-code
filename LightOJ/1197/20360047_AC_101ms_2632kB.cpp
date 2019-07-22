#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n) printf("%d%c", A[i],i==n-1?'\n':' '); }
#define SHOW2(A,m,n) { REP(j,m) SHOW1(A[j],n) }
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
const int MAXN = 2e5+9, MAXM = 3e3+9;

bool vis[MAXN];
LL prime[MAXN/10],tot;
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
bool notp[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    getPrime(MAXN-1);
    int T; scanf("%d", &T);
    FOR(kase,1,T) {
        int l,r; scanf("%d%d", &l,&r);
        memset(notp,0,sizeof(notp));
        REP(i,tot) {
            LL j=prime[i]*prime[i];
            if (j>r) break;
            for (j=max(j,(l+prime[i]-1)/prime[i]*prime[i]); j<=r; j+=prime[i]) {
                notp[j-l]=1;
            }
        }
        int ans=0;
        FOR(i,0,r-l) ans+=(notp[i]==0);
        if (l==1) ans--;
        printf("Case %d: %d\n", kase,ans);
    }

    return 0;
}


































