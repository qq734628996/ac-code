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
const int MAXN = 128, INF = 0x3f3f3f3f, MOD = 998244353;
const int MAXM = 11;
int m, n, cnt[1<<MAXM][1<<MAXM], d[1<<MAXM][1<<MAXM], vis[1<<MAXM][1<<MAXM], kase;
char buf[128];

int dp(int s, int a)
{
    if (cnt[s][a] <= 1) return 0;
    if (cnt[s][a] == 2) return 1;

    int& ans = d[s][a];
    if (vis[s][a] == kase) return ans;
    vis[s][a] = kase;

    ans = m;
    REP(k,m) if (!(s & (1<<k))) {
        int s2 = s|(1<<k), a2 = a|(1<<k);
        if (cnt[s2][a2] >= 1 && cnt[s2][a] >= 1)
            ans = min(ans, max(dp(s2, a2), dp(s2, a)) + 1);
    }
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d", &m, &n), m) {
        ++kase;
        REP(s,(1<<m)) {
            for (int a = s; a; a = (a-1)&s)
                cnt[s][a] = 0;
            cnt[s][0] = 0;
        }
        REP(j,n) {
            scanf("%s", buf);
            int x = 0;
            REP(j,m) if (buf[j] == '1') x |= (1<<j);
            REP(s,(1<<m)) cnt[s][s & x]++;
        }
        printf("%d\n", dp(0, 0));
    }

    return 0;
}



















































































