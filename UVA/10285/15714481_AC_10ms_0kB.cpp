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
const int MAXN = 1e2+5, MAXM = 3e3+5, INF = 0x3f3f3f3f, MOD = 1e9+7;

int T, m, n, a[MAXN][MAXN], d[MAXN][MAXN];
char s[MAXM];
const int dr[] = {0,0,1,-1};
const int dc[] = {1,-1,0,0};
inline bool vld(int i, int j) { return 0<=i && i<m && 0<=j && j<n; }

int dp(int i, int j)
{
    int& ans = d[i][j];
    if (ans) return ans;
    REP(k,4) {
        int x = i+dr[k], y = j+dc[k];
        if (vld(x,y) && a[x][y] > a[i][j]) {
            ans = max(ans, dp(x,y));
        }
    }
    return ans += 1;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        scanf("%s%d%d", s, &m, &n);
        REP(i,m)REP(j,n) scanf("%d", &a[i][j]);
        memset(d, 0, sizeof(d));
        int ans = 0;
        REP(i,m)REP(j,n) ans = max(ans, dp(i,j));
        printf("%s: %d\n", s, ans);
    }

    return 0;
}


















































































