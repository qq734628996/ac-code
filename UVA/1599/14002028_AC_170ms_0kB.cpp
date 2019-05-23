#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define TR(e,x) for(auto e = x.begin(); e != x.end(); e++)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n-1) printf("%d ", A[i]); printf("%d\n", A[n-1]); }
#define SHOW2(A,m,n) { REP(i,m) { REP(j,n-1) printf("%d ", A[i][j]); printf("%d\n", A[i][n-1]); } }
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)((x).size())
typedef long long LL;
const int MAXN  = 1e5+5, INF = ~0U>>1, MOD = ~0U>>1;

int n, m, d[MAXN], p[MAXN], ans[MAXN];
struct edge {
    int v, c;
};
vector<edge> adj[MAXN];

void rev_bfs()
{
    memset(d+1,-1,sizeof(int)*n);
    queue<int> Q;
    Q.push(n); d[n] = 0;
    while (true) {
        int i = Q.front(); Q.pop();
        if (i == 1) return;
        REP(j,SZ(adj[i]))if(d[adj[i][j].v] == -1) {
            Q.push(adj[i][j].v);
            d[adj[i][j].v] = d[i] + 1;
        }
    }
}
void bfs()
{
    memset(p+1,0,sizeof(int)*n);
    memset(ans+1,0,sizeof(int)*n);
    queue<int> Q;
    Q.push(1);
    while (true) {
        int i = Q.front(); Q.pop();
        if (i == n) return;
        int minc = INF; vector<edge> V;
        REP(j,SZ(adj[i]))if(d[adj[i][j].v] == d[i]-1) {
            minc = min(minc, adj[i][j].c);
            V.push_back(adj[i][j]);
        }
        REP(j,SZ(V))if(V[j].c == minc) {
            if (p[V[j].v]) {
                if (V[j].c < ans[V[j].v]) {
                    p[V[j].v] = i;
                    ans[V[j].v] = V[j].c;
                }
            } else {
                Q.push(V[j].v);
                p[V[j].v] = i;
                ans[V[j].v] = V[j].c;
            }
        }
    }
}
void printAns()
{
    printf("%d\n", d[1]);
    vector<int> V;
    for (int i = n; i != 1; i = p[i])
        V.push_back(ans[i]);
    for (int i = SZ(V)-1; i > 0; i--)
        printf("%d ", V[i]);
    printf("%d\n", V[0]);
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d%d", &n, &m)) {
        FOR(i,1,n)adj[i].clear();
        int a, b, c;
        REP(i,m) {
            scanf("%d%d%d", &a, &b, &c);
            adj[a].push_back((edge){b,c});
            adj[b].push_back((edge){a,c});
        }
        rev_bfs();
        bfs();
        printAns();
    }


    return 0;
}






















