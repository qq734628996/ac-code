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

int n;
LL a[MAXN];
typedef pair<LL,LL> pll;
set<pll> S;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n)==1 && n) {
        FOR(i,1,n) scanf("%lld", &a[i]);
        sort(a+1,a+1+n);
        S.clear();
        FOR(i,1,n)FOR(j,i+1,n) S.insert(pll(a[i]+a[j],a[i]));
        bool fail=true;
        ROF(i,1,n)ROF(j,1,i-1) {
            auto it=S.lower_bound(pll(a[i]-a[j],-INF));
            if (it != S.end() && it->fi==a[i]-a[j]) {
                int x=it->se, y=it->fi-it->se;
                if (x!=a[i] && x!=a[j] && y!=a[i] && y!=a[j]) {
                    fail=false;
                    printf("%d\n", a[i]);
                    goto OUT;
                }
            }
        }
        OUT:
        if (fail) puts("no solution");
    }

    return 0;
}









































