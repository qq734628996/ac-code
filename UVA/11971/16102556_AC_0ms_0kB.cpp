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
const int MAXN = 4e5+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 10056;

LL gcd(LL a, LL b) { return b == 0 ? a : gcd(b, a%b); }

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T, kase = 0; scanf("%d", &T);
    while (T--) {
        int n, k; scanf("%d%d", &n, &k);
        LL a = (1LL<<k)-k-1, b = (1LL<<k);
        LL g = gcd(a, b);
        printf("Case #%d: %lld/%lld\n", ++kase, a/g, b/g);
    }

    return 0;
}













































































