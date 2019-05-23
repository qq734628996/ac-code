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

int tmp,n,m,a[MAXN],b[MAXN],d[MAXN],g[MAXN];


int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    FOR(kase,1,T) {
        scanf("%d%d%d", &tmp,&n,&m);
        n++, m++;
        REP(i,n) scanf("%d", &a[i]);
        REP(i,m) {
            int x; scanf("%d", &x);
            b[x]=i;
        }
        REP(i,n) a[i]=b[a[i]];
        memset(g,0x3f,sizeof(int)*(n+1));
        int ma=0;
        REP(i,n) {
            int k=lower_bound(g+1,g+1+ma,a[i])-g;
            d[i]=k;
            g[k]=a[i];
            ma=max(ma,k);
        }
        printf("Case %d: %d\n", kase,ma);
    }

    return 0;
}










































