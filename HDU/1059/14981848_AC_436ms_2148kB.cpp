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
const int MAXN = 2e5+5, INF = 0x3f3f3f3f, MOD = 998244353;

int m[10], dp[MAXN], V, kase;

void ZeroOnePack(int C, int W)
{ ROF(i,C,V) dp[i] = max(dp[i], dp[i-C]+W); }
void CompletePack(int C, int W)
{ FOR(i,C,V) dp[i] = max(dp[i], dp[i-C]+W); }
void MultiplePack(int C, int W, int M)
{
    if (V <= M*C) { CompletePack(C, W); return; }
    for (int k = 1; k < M; M -= k, k <<= 1)
        ZeroOnePack(k*C, k*W);
    if (M) ZeroOnePack(M*C, M*W);
}

bool read()
{
    FOR(i,1,6) scanf("%d", &m[i]);
    V = 0;
    FOR(i,1,6) V += m[i]*i;
    return V;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (read()) {
        printf("Collection #%d:\n", ++kase);
        if (V & 1) { puts("Can't be divided.\n"); continue; }
        V >>= 1;
        memset(dp, 0, sizeof(dp));
        FOR(i,1,6) MultiplePack(i, i, m[i]);
        if (dp[V] == V) puts("Can be divided.\n");
        else puts("Can't be divided.\n");
    }

    return 0;
}




















































































