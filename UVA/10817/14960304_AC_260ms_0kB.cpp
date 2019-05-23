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
const int MAXN  = 125, INF = 0x3f3f3f3f, MOD = 998244353;
const int MAXS = 9;
int m, n, s, c[MAXN], st[MAXN], d[MAXN][1<<MAXS][1<<MAXS], x;
char buf[205];

int dp(int i, int s0, int s1, int s2)
{
    if (i == m+n) return s2 == (1<<s) -1 ? 0 : INF;
    int& ans = d[i][s1][s2];
    if (ans >= 0) return ans;
    ans = INF;
    if (i >= m) ans = dp(i+1, s0, s1, s2);
    int m0 = st[i] & s0, m1 = st[i] & s1;
    s0 ^= m0; s1 = (s1 ^ m1) | m0; s2 |= m1;
    ans = min(ans, c[i] + dp(i+1, s0, s1, s2));
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d%d", &s, &m, &n), getchar(), s) {
        REP(i,m+n) {
            fgets(buf, 205, stdin);
            char* p = strtok(buf, " ");
            sscanf(p, "%d", &c[i]);
            st[i] = 0;
            while (p = strtok(NULL, " "), p) sscanf(p, "%d", &x), st[i] |= 1<<(x-1);
        }
        memset(d, -1, sizeof(d));
        printf("%d\n", dp(0, (1<<s)-1, 0, 0));
    }

    return 0;
}




















































































