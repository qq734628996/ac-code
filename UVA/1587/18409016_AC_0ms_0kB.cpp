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
const int MAXN = 1e3+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

pii a[6];
bool jdg()
{
    REP(i,3) if (a[i*2] != a[i*2+1]) return false;
    if (a[0].fi!=a[2].fi) return false;
    int mi=min(a[0].se,a[2].se);
    int ma=max(a[0].se,a[2].se);
    return mi==a[4].fi && ma==a[4].se;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL


    while (scanf("%d%d", &a[0].fi,&a[0].se)==2) {
        FOR(i,1,5) scanf("%d%d", &a[i].fi,&a[i].se);
        REP(i,6) if (a[i].fi>a[i].se) swap(a[i].fi,a[i].se);
        sort(a,a+6);
        puts(jdg() ? "POSSIBLE" : "IMPOSSIBLE");
    }

    return 0;
}














































