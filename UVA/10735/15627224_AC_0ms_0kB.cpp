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

int T, n, m, u[MAXN], v[MAXN], in[MAXN], out[MAXN];
char op[MAXN][2];
vector<pii> G[MAXN];
stack<int> ans;

void euler(int i)
{
    for (auto& j : G[i]) if (!j.se) {
        j.se = 1;
        euler(j.fi);
        ans.push(j.fi);
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    REP(kase,T) {
        if (kase) puts("");
        scanf("%d%d", &n, &m);
        solve.init(n+1);
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        REP(i,m) {
            scanf("%d%d%s", &u[i], &v[i], op[i]);
            out[u[i]]++, in[v[i]]++;
            if (op[i][0] == 'U') solve.AddEdge(v[i], u[i], 1);
        }
        int cnt1 = 0, cnt2 = 0;
        bool fail = false;
        FOR(i,1,n) {
            if ((in[i]-out[i])&1) { fail = true; break; }
            int x = abs(in[i]-out[i])/2;
            if (in[i] > out[i]) solve.AddEdge(0, i, x), cnt1 += x;
            else if (out[i] > in[i]) solve.AddEdge(i, n+1, x), cnt2 += x;
        }
        if (fail || cnt1 != cnt2 || solve.Maxflow(0,n+1) != cnt1) {
            puts("No euler circuit exist");
            continue;
        }
        FOR(i,1,n) G[i].clear();
        REP(i,m) if (op[i][0] == 'D') G[u[i]].pb(pii(v[i],0));
        for (auto& i : solve.edges) if (i.from && i.to != n+1 && i.cap) {
            if (i.flow) G[i.from].pb(pii(i.to,0));
            else G[i.to].pb(pii(i.from,0));
        }
        euler(1);
        putchar('1');
        for (; !ans.empty(); ans.pop()) printf(" %d", ans.top());
        puts("");
    }

    return 0;
}


















































































