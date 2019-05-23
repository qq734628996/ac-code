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
const int MAXN = 4e2+5, MAXM = 1e6+5, INF = 0x3f3f3f3f, MOD = 998244353;

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
        Q.push(s);
        d[s] = 0; vis[s] = 1;
        while (!Q.empty()) {
            int x = Q.front(); Q.pop();
            REP(i,SZ(G[x])) {
                Edge& e = edges[G[x][i]];
                if (!vis[e.to] && e.cap > e.flow) {
                    vis[e.to] = 1;
                    d[e.to] = d[x] + 1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    int DFS(int x, int a)
    {
        if (x == t || !a) return a;
        int flow = 0, f;
        for (int& i = cur[x]; i < SZ(G[x]); i++) {
            Edge& e = edges[G[x][i]];
            if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap-e.flow))) > 0) {
                e.flow += f;
                edges[G[x][i]^1].flow -= f;
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

int T, n, m, k, a[MAXN], b[MAXN], c[MAXN][2], tot;
map<string, int> mp;
int ID(string& str)
{
    if (mp.count(str)) return mp[str];
    return mp[str] = tot++;
}
void init()
{
    mp.clear();
    tot = 1;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    cin >> T;
    REP(kase,T) {
        if (kase) puts("");
        init();
        string s[2];
        cin >> n; REP(i,n) { cin >> s[0]; a[i] = ID(s[0]); }
        cin >> m; REP(i,m) { REP(j,2) cin >> s[j]; b[i] = ID(s[1]); }
        cin >> k; REP(i,k) { REP(j,2) cin >> s[j], c[i][j] = ID(s[j]); }
        solve.init(tot);
        REP(i,n) solve.AddEdge(0,a[i],1);
        REP(i,m) solve.AddEdge(b[i],tot,1);
        REP(i,k) solve.AddEdge(c[i][1],c[i][0],INF);
        cout << m - solve.Maxflow(0,tot) << endl;
    }

    return 0;
}


















































































