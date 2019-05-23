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

int n,p,q,a[MAXN],b[MAXN],d[MAXN],g[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    FOR(kase,1,T) {
        scanf("%d%d%d", &n,&p,&q);
        memset(b,-1,sizeof(int)*(n*n+1));
        p++, q++;
        REP(i,p) {
            int x; scanf("%d", &x);
            b[x]=i;
        }
        int tot=0;
        REP(i,q) {
            int x; scanf("%d", &x);
            if (~b[x]) a[tot++]=b[x];
        }
        int ma=0;
        memset(g,0x3f,sizeof(int)*(tot+1));
        REP(i,tot) {
            int k=lower_bound(g+1,g+ma+1,a[i])-g;
            d[i]=k;
            g[k]=a[i];
            ma=max(ma,k);
        }
        printf("Case %d: %d\n", kase,ma);
    }

    return 0;
}










































