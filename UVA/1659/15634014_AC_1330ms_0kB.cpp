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
const int MAXN = 5e2+5, MAXM = 5e2+5, INF = 0x3f3f3f3f, MOD = 998244353;

struct Edge {
    int from, to, cap, flow;
    double cost;
};
struct MCMF {
    int n, m;
    vector<Edge> edges;
    vector<int> G[MAXN];
    bool inq[MAXN];
    double d[MAXN];
    int p[MAXN], a[MAXN];

    void init(int n)
    {
        this->n = n;
        edges.clear();
        FOR(i,0,n) G[i].clear();
    }

    void AddEdge(int from, int to, int cap, double cost)
    {
        edges.pb((Edge){from, to, cap, 0, cost});
        edges.pb((Edge){to, from, 0, 0, -cost});
        m = SZ(edges);
        G[from].pb(m-2);
        G[to].pb(m-1);
    }

    bool spfa(int s, int t, int& flow, double& cost)
    {
        FOR(i,0,n) d[i] = 1e18;
        memset(inq, 0, sizeof(inq));
        queue<int> Q;
        Q.push(s); d[s] = 0; a[s] = INF;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            inq[u] = 0;
            REP(i,SZ(G[u])) {
                Edge& e = edges[G[u][i]];
                if (e.cap > e.flow && d[e.to] > d[u] + e.cost) {
                    d[e.to] = d[u] + e.cost;
                    p[e.to] = G[u][i];
                    a[e.to] = min(a[u], e.cap - e.flow);
                    if (!inq[e.to]) { inq[e.to] = 1; Q.push(e.to); }
                }
            }
        }
        if (d[t] == 1e18) return false;
        flow += a[t];
        cost += d[t] * a[t];
        for (int u = t; u != s; u = edges[p[u]].from) {
            edges[p[u]].flow += a[t];
            edges[p[u]^1].flow -= a[t];
        }
        return true;
    }

    int mcmf(int s, int t, double& cost)
    {
        int flow = 0; cost = 0;
        while (spfa(s, t, flow, cost));
        return flow;
    }
} solve;

int n, a, b, x[MAXN], y[MAXN], kase;
vector<int> E[MAXN];
inline double dis(int i, int j) { return hypot(x[i]-x[j], y[i]-y[j]); }

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d%d", &n, &a, &b), n) {
        FOR(i,1,n) E[i].clear();
        FOR(i,1,n) {
            scanf("%d%d", &x[i], &y[i]);
            int x; while (scanf("%d", &x), x) E[i].pb(x);
        }
        solve.init(n+1);
        double sum = 0;
        FOR(i,1,n) {
            for (auto& j : E[i]) {
                double cost = b - dis(i, j) * a;
                if (cost >= 0) {
                    solve.AddEdge(i, j, 1, cost);
                } else {
                    sum += cost;
                    solve.AddEdge(0, j, 1, 0);
                    solve.AddEdge(j, i, 1, -cost);
                    solve.AddEdge(i, n+1, 1, 0);
                }
            }
        }
        double cost;
        solve.mcmf(0, n+1, cost);
        printf("Case %d: %.2f\n", ++kase, -(sum+cost)+1e-9);
    }

    return 0;
}


















































































