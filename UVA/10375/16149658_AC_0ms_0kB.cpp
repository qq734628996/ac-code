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
const int MAXN = 1e4+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 1e8+7;

typedef long double ld;
ld logF[MAXN];
ld logC(int n, int m) { return logF[n] - logF[m] - logF[n-m]; }

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    FOR(i,2,MAXN-1) logF[i] = logF[i-1] + log(i);
    int p, q, r, s;
    while (~scanf("%d%d%d%d", &p, &q, &r, &s)) {
        printf("%.5Lf\n", exp(logC(p,q) - logC(r, s)));
    }

    return 0;
}













































































