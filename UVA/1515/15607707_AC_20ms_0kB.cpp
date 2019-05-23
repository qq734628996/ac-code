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
const int MAXN = 3e3+5, MAXM = 1e6+5, INF = 0x3f3f3f3f, MOD = 998244353;

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
        edges.clear();
        this->n = n;
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
            if (d[u] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0) {
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

int T, n, m, d, f, b;
char s[60][60];
inline int ID(int i, int j) { return (i-1)*n+j; }
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
inline bool vld(int i, int j) { return 1<=i && i<=m && 1<=j && j<=n; }

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d%d", &n, &m, &d, &f, &b);
        FOR(i,1,m) scanf("%s", s[i]+1);
        int cost = 0;
        FOR(i,1,m)FOR(j,1,n) if ((i==1 || j==1 || i==m || j==n) && s[i][j]=='.') {
            s[i][j] = '#';
            cost += f;
        }
        solve.init(m*n+1);
        FOR(i,1,m)FOR(j,1,n) {
            if (s[i][j] == '#') {
                int cap = d;
                if (i==1 || j==1 || i==m || j==n) cap = INF;
                solve.AddEdge(0, ID(i,j), cap);
            } else solve.AddEdge(ID(i,j), m*n+1, f);
            REP(k,4) {
                int x = i+dr[k], y = j+dc[k];
                if (vld(x,y)) solve.AddEdge(ID(i,j), ID(x,y), b);
            }
        }
        printf("%d\n", cost + solve.Maxflow(0, m*n+1));
    }

    return 0;
}


















































































