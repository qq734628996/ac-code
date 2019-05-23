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
const int MAXN = 3e2+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 1e8+7;

int g[MAXN][MAXN], m, n;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }
void getgcd(int n) { FOR(i,1,n)FOR(j,i,n) g[i][j] = g[j][i] = gcd(i,j); }

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    getgcd(MAXN-1);
    while (scanf("%d%d", &m, &n), m) {
        LL ans = 0;
        FOR(i,1,m)FOR(j,1,n) if (g[i][j] == 1) {
            ans += (m-i)*(n-j) - max(0,m-2*i)*max(0,n-2*j);
        }
        printf("%lld\n", ans*2);
    }

    return 0;
}













































































