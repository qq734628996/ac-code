#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>

#include <iostream>
#include <algorithm>
//#include <unordered_map>
//#include <unordered_set>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
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
const int MAXN = 2e3+5, MAXM = 1e6+5, INF = 0x3f3f3f3f, MOD = 998244353;

struct Edge {
    int from, to, cap, flow, cost;
};
struct MCMF {
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[MAXN];
    bool inq[MAXN];
    int d[MAXN], p[MAXN], a[MAXN];

    void init(int n)
    {
        this->n = n;
        FOR(i,0,n) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from, int to, int cap, int cost)
    {
        edges.pb((Edge){from, to, cap, 0, cost});
        edges.pb((Edge){to, from, 0, 0, -cost});
        m = SZ(edges);
        G[from].pb(m-2);
        G[to].pb(m-1);
    }

    bool spfa(int s, int t, int& flow, LL& cost)
    {
        memset(d, 0x3f, sizeof(d));
        memset(inq, 0, sizeof(inq));
        d[s] = 0; inq[s] = 1; p[s] = 0; a[s] = INF;
        queue<int> Q;
        Q.push(s);
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            inq[u] = 0;
            REP(i,SZ(G[u])) {
                Edge& e = edges[G[u][i]];
                if (e.cap > e.flow && d[e.to] > d[u] + e.cost) {
                    d[e.to] = d[u] + e.cost;
                    p[e.to] = G[u][i];
                    a[e.to] = min(a[u], e.cap - e.flow);
                    if (!inq[e.to]) { Q.push(e.to); inq[e.to] = 1; }
                }
            }
        }
        if (d[t] == INF) return false;
        flow += a[t];
        cost += d[t] * a[t];
        for (int u = t; u != s; u = edges[p[u]].from) {
            edges[p[u]].flow += a[t];
            edges[p[u]^1].flow -= a[t];
        }
        return true;
    }

    int mcmf(int s, int t, LL& cost)
    {
        int flow = 0; cost = 0;
        while (spfa(s, t, flow, cost));
        return flow;
    }
} solve;

int n, m;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d%d", &n, &m)) {
        solve.init(2*n);
        solve.AddEdge(0, 1, 2, 0);
        solve.AddEdge(n, n+1, 2, 0);
        FOR(i,2,n-1) solve.AddEdge(i, i+n, 1, 0);
        while (m--) {
            int u, v, w; scanf("%d%d%d", &u, &v, &w);
            solve.AddEdge(u == 1 ? u : u+n, v, 1, w);
        }
        LL ans;
        solve.mcmf(0, n+1, ans);
        printf("%lld\n", ans);
    }

    return 0;
}


















































































