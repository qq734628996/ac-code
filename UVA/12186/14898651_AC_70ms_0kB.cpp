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
const int MAXN  = 1e5+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n, T, x;
vector<int> son[MAXN];

int dp(int i)
{
    if (!SZ(son[i])) return 1;
    vector<int> d;
    REP(j,SZ(son[i])) d.pb(dp(son[i][j]));
    sort(ALL(d));
    int c = (SZ(son[i])*T - 1) / 100 + 1, ans = 0;
    REP(j,c) ans += d[j];
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d", &n, &T), n) {
        REP(i,n+1) son[i].clear();
        FOR(i,1,n) { scanf("%d", &x); son[x].pb(i); }
        printf("%d\n", dp(0));
    }

    return 0;
}




















































































