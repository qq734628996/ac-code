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

struct Edge {
    int from, to, cap, flow;
};
struct dinic {
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[MAXN];
    bool vis[MAXN];
    int d[MAXN], cur[MAXN];

    void init(int n)
    {
        this->n = n;
        edges.clear();
        FOR(i,0,n) G[i].clear();
    }

    void AddEdge(int from, int to, int cap)
    {
        edges.pb((Edge){from, to, cap, 0});
        edges.pb((Edge){to, from, 0, 0});
        m = SZ(edges);
        G[from].pb(m-2);
        G[to].pb(m-1);
    }

    bool BFS()
    {
        memset(vis, 0, sizeof(vis));
        queue<int> Q;
        Q.push(s); d[s] = 0; vis[s] = 1;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            REP(i,SZ(G[u])) {
                Edge& e = edges[G[u][i]];
                if (!vis[e.to] && e.cap > e.flow) {
                    vis[e.to] = 1;
                    d[e.to] = d[u] + 1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    int DFS(int u, int a)
    {
        if (u == t || !a) return a;
        int flow = 0, f;
        for (int& i = cur[u]; i < SZ(G[u]); i++) {
            Edge& e = edges[G[u][i]];
            if (d[e.to] == d[u] + 1 && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0) {
                e.flow += f;
                edges[G[u][i]^1].flow -= f;
                flow += f;
                a -= f;
                if (!a) break;
            }
        }
        return flow;
    }

    int Maxflow(int s, int t)
    {
        this->s = s; this->t = t;
        int flow = 0;
        while (BFS()) {
            memset(cur, 0, sizeof(cur));
            flow += DFS(s, INF);
        }
        return flow;
    }
} solve;

int n, m, s, t, kase;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d%d%d", &n, &s, &t, &m), n) {
        solve.init(n);
        REP(i,m) {
            int x, y, z; scanf("%d%d%d", &x, &y, &z);
            solve.AddEdge(x, y, z);
            solve.AddEdge(y, x, z);
        }
        printf("Network %d\nThe bandwidth is %d.\n\n", ++kase, solve.Maxflow(s, t));
    }

    return 0;
}


















































































