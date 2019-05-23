#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define TR(e,x) for(auto e = x.begin(); e != x.end(); e++)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n-1) printf("%d ", A[i]); printf("%d\n", A[n-1]); }
#define SHOW2(A,m,n) { REP(i,m) { REP(j,n-1) printf("%d ", A[i][j]); printf("%d\n", A[i][n-1]); } }
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)((x).size())
typedef long long LL;
typedef pair<int, int> pii;
const int MAXN  = 5e2+5, INF = ~0U>>1, MOD = ~0U>>1;

int T, k, a, b, kase;

LL qpow(LL a, LL b)
{
    if (!b) return 1;
    if (b&1) return qpow(a, b-1) * a;
    return qpow(a, b/2) * qpow(a, b/2);
}

LL f(int k, int i)
{
    if (!i) return 0;
    if (!k) return 1;
    if (i <= (1<<(k-1))) return 2*f(k-1, i);
    return 2*qpow(3, k-1) + f(k-1, i-(1<<(k-1)));
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &k, &a, &b);
        printf("Case %d: ", ++kase);
        cout << f(k, b) - f(k, a-1) << endl;
    }

    return 0;
}











































































