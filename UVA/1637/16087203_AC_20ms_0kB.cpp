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
const int MAXN = 2e6+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 1e9+7;

double d[MAXN];
int vis[MAXN], kase;
char s[9][4][3];
int st[9];

double dp()
{
    int id = 0;
    REP(i,9) id = id*5+st[i];
    if (!id) return 1;
    if (vis[id] == kase) return d[id];
    vis[id] = kase;
    d[id] = 0;
    vector<pii> V;
    REP(i,9) if (st[i]) {
        FOR(j,i+1,8) if (st[j] && s[i][st[i]-1][0] == s[j][st[j]-1][0]) V.pb(pii(i,j));
    }
    REP(k,SZ(V)) {
        int i = V[k].fi, j = V[k].se;
        st[i]--; st[j]--;
        d[id] += dp();
        st[i]++; st[j]++;
    }
    if (SZ(V)) d[id] /= SZ(V);
    return d[id];
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%s", s[0][0])) {
        ++kase;
        REP(i,9)REP(j,4) {
            if (!i && !j) continue;
            scanf("%s", s[i][j]);
        }
        REP(i,9) st[i] = 4;
        printf("%.6f\n", dp());
    }

    return 0;
}













































































