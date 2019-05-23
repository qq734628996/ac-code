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
const int MAXN  = 5e3+5, INF = 0x3f3f3f3f, MOD = 998244353;

int T, l[2][26], r[2][26], n[2], dp[MAXN][MAXN];
char s[2][MAXN];

inline int f(int i, int j)
{
    int cnt = 0;
    REP(k,26)if((l[0][k]<=i || l[1][k]<=j) && (i<r[0][k] || j<r[1][k])) cnt++;
    return cnt; //返回有多少元素已经出现但未结束
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        REP(i,2) scanf("%s", s[i]+1);
        REP(i,2) n[i] = strlen(s[i]+1);
        REP(i,2) {
            REP(j,26) l[i][j] = INF, r[i][j] = -INF;
            FOR(j,1,n[i]) r[i][s[i][j]-'A'] = j;
            ROF(j,1,n[i]) l[i][s[i][j]-'A'] = j;
        }
        FOR(i,1,n[0]) dp[i][0] = dp[i-1][0] + f(i-1, 0);
        FOR(j,1,n[1]) dp[0][j] = dp[0][j-1] + f(0, j-1);
        FOR(i,1,n[0])FOR(j,1,n[1]) { //dp[i][j]表示已经转移了i,j后最少花销多少
            dp[i][j] = min(dp[i-1][j] + f(i-1, j), dp[i][j-1] + f(i, j-1));
        }
        printf("%d\n", dp[n[0]][n[1]]);
    }

    return 0;
}




















































































