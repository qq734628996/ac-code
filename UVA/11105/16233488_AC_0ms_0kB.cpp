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
const int MAXN = 1e6+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 1e9+7;

int vis[MAXN], H[MAXN], tot, ans[MAXN];
void sieve(int n)
{
    for (int i = 5; i <= n; i += 4) {
        if (!vis[i]) {
            H[tot++] = i;
            REP(j,tot) {
                if (i*H[j] > n) break;
                vis[i*H[j]] = 1;
                if (i%H[j] == 0) break;
            }
        } else {
            REP(j,tot) {
                if (i*H[j] > n) break;
                vis[i*H[j]] = 2;
                if (i%H[j] == 0) break;
            }
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    sieve(MAXN-1);
    FOR(i,1,MAXN-1) ans[i] = ans[i-1]+(vis[i]==1);
    int n;
    while (scanf("%d", &n), n) {
        printf("%d %d\n", n, ans[n]);
    }

    return 0;
}













































































