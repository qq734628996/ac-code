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
const int MAXN  = 25, INF = ~0U>>1, MOD = ~0U>>1;

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
struct point {
    int x, y, cnt;
};
int T, m, n, maxl, G[MAXN][MAXN], cost[MAXN][MAXN], d[MAXN][MAXN];
#define vld(x,y) (0<=x && x<m && 0<=y && y<n)

int bfs()
{
    if (maxl <= 0 && G[0][0]) return -1;
    memset(cost, -1, sizeof(cost));
    memset(d, -1, sizeof(d));
    queue<point> Q;
    Q.push((point){0,0,cost[0][0] = G[0][0]});
    d[0][0] = 0;
    for ( ; !Q.empty(); Q.pop()) {
        point& p = Q.front();
        if (p.x == m-1 && p.y == n-1) return d[m-1][n-1];
        REP(k,4) {
            int i = p.x + dr[k], j = p.y + dc[k];
            if (vld(i,j)) {
                if (d[i][j] == -1) {
                    if (G[i][j] && p.cnt < maxl) {
                        Q.push((point){i,j,p.cnt+1});
                        cost[i][j] = p.cnt + 1;
                        d[i][j] = d[p.x][p.y] + 1;
                    } else if (!G[i][j]) {
                        Q.push((point){i,j,0});
                        d[i][j] = d[p.x][p.y] + 1;
                    }
                } else if (G[i][j] && p.cnt < cost[i][j] && p.cnt < maxl) {
                    Q.push((point){i,j,p.cnt+1});
                    cost[i][j] = p.cnt + 1;
                    d[i][j] = d[p.x][p.y] + 1;
                }
            }
        }
    }
    return -1;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &m, &n, &maxl);
        REP(i,m)REP(j,n)scanf("%d", &G[i][j]);
        printf("%d\n", bfs());
    }

    return 0;
}






















