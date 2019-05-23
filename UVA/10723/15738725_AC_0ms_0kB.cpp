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
const int MAXN = 6e1+5, MAXM = 3e3+5, INF = 0x3f3f3f3f, MOD = 1e9+7;

char s[MAXN], t[MAXN];
int m, n, cnt, ans, vis[MAXN][MAXN][MAXN], kase;
LL d[MAXN][MAXN][MAXN];

LL dp(int i, int j, int k)
{
    if (k <= 0 && (~i || ~j)) return 0;
    if (i == -1) return k-j-1 == 0;
    if (j == -1) return k-i-1 == 0;
    LL& ans = d[i][j][k];
    if (vis[i][j][k] == kase) return ans;
    vis[i][j][k] = kase;
    ans = 0;
    if (i >= 0 && j >= 0 && s[i] == t[j]) ans += dp(i-1,j-1,k-1);
    else {
        if (i >= 0) ans += dp(i-1,j,k-1);
        if (j >= 0) ans += dp(i,j-1,k-1);
    }
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (getchar() != '\n');
    while (T--) {
        printf("Case #%d: ", ++kase);
        gets(s); gets(t);
        m = strlen(s); n = strlen(t);
        if (!m) { printf("%d 1\n", n); continue; }
        if (!n) { printf("%d 1\n", m); continue; }
        int i = 0;
        while (++i) {
            if (dp(m-1,n-1,i)) break;
        }
        printf("%d %lld\n", i, d[m-1][n-1][i]);
    }

    return 0;
}


















































































