#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
#define TR(e,x) for(auto e = x.begin(); e != x.end(); e++)
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
const int MAXN = 1e2+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 1e9+7;



int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int n, r, kase = 0;
    while (scanf("%d%d", &n, &r), n) {
        double P[25], sum[25] = {0};
        REP(i,n) scanf("%lf", &P[i]);
        if (!r) {
            printf("Case %d:\n", ++kase);
            REP(i,n) printf("%.6f\n", 0.0);
            continue;
        }
        for (int i = (1<<r)-1; i < (1<<n); ) {
            double prob = 1;
            REP(j,n) prob *= ((i & (1<<j)) ? P[j] : 1-P[j]);
            sum[n] += prob;
            REP(j,n) if (i & (1<<j)) sum[j] += prob;
            int t = i & -i;
            i = (i + t) | (((i ^ (i+t)) >> 2) / t);
        }
        printf("Case %d:\n", ++kase);
        REP(i,n) printf("%.6f\n", sum[i]/sum[n]);
    }

    return 0;
}













































































