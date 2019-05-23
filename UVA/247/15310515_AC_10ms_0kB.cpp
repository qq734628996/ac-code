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
const int MAXN = 30, INF = 0x3f3f3f3f, MOD = 998244353;

vector<string> nameSet;
map<string, int> nameID;
int ID(string& str)
{
    if (nameID.count(str)) return nameID[str];
    nameSet.pb(str);
    return nameID[str] = SZ(nameSet) - 1;
}
int n, m, g[MAXN][MAXN], G[MAXN][MAXN], vis[MAXN], kase;
string s, t;

void dfs(int i)
{
    REP(j,n) if (!vis[j] && G[i][j]) {
        vis[j] = 1;
        cout << ", " << nameSet[j];
        dfs(j);
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (cin >> n >> m, n) {
        if (kase++) puts("");
        printf("Calling circles for data set %d:\n", kase);
        nameSet.clear();
        nameID.clear();
        memset(g, 0, sizeof(g));
        memset(G, 0, sizeof(G));
        memset(vis, 0, sizeof(vis));
        REP(i,m) { cin >> s >> t; g[ID(s)][ID(t)] = 1; }
        REP(k,n)REP(i,n)REP(j,n) g[i][j] |= g[i][k] && g[k][j];
        REP(i,n)FOR(j,i+1,n-1) if (g[i][j] && g[j][i]) G[i][j] = G[j][i] = 1;
        REP(i,n) if (!vis[i]) {
            vis[i] = 1;
            cout << nameSet[i];
            dfs(i);
            cout << endl;
        }
    }

    return 0;
}


















































































