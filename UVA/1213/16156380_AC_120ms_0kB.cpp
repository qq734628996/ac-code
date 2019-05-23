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
const int MAXN = 2e3+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 1e8+7;

int np[MAXN], prime[MAXN], tot, d[MAXN][200][14], vis[MAXN][200][14];
void sieve(int n)
{
    FOR(i,2,n) {
        if (!np[i]) prime[tot++] = i;
        REP(j,tot) {
            if (i*prime[j] > n) break;
            np[i*prime[j]] = 1;
            if (i%prime[j] == 0) break;
        }
    }
}

int dp(int i, int j, int k)
{
    if (!k) return !i;
    int& ans = d[i][j][k];
    if (vis[i][j][k]) return ans;
    vis[i][j][k] = 1;
    REP(l,j) {
        if (i-prime[l] < 0) break;
        ans += dp(i-prime[l],l,k-1);
    }
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    sieve(1120);
    int i, j;
    while (scanf("%d%d", &i, &j), i)
        printf("%d\n", dp(i,tot,j));

    return 0;
}













































































