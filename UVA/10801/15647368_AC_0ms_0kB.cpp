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
const int MAXN = 1e2+5, MAXM = 5e2+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n, ed, a[MAXN], d[MAXN], vis[MAXN];
vector<int> E[MAXN];
vector<int> S[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d%d", &n, &ed)) {
        REP(i,MAXN) E[i].clear(), S[i].clear();
        REP(i,n) scanf("%d", &a[i]);
        while (getchar() != '\n');
        string buf;
        REP(i,n) {
            getline(cin, buf);
            stringstream ss(buf);
            int x; while (ss >> x) {
                E[i].pb(x);
                S[x].pb(i);
            }
        }
        if (!ed) { puts("0"); continue; }
        memset(d, 0x3f, sizeof(d));
        memset(vis, 0, sizeof(vis));
        priority_queue<pii> pq;
        pq.push(pii(d[0] = 0, 0));
        while (!pq.empty()) {
            int u = pq.top().se; pq.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            REP(i,SZ(S[u])) {
                int now = S[u][i];
                REP(j,SZ(E[now])) {
                    int v = E[now][j];
                    if (d[v] > 60 + d[u] + abs(u-v)*a[now]) {
                        d[v] = 60 + d[u] + abs(u-v)*a[now];
                        pq.push(pii(-d[v], v));
                    }
                }
            }
        }
        if (d[ed] == INF) puts("IMPOSSIBLE");
        else printf("%d\n", d[ed]-60);
    }

    return 0;
}


















































































