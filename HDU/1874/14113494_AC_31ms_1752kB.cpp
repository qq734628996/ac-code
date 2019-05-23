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
const int MAXN  = 205, INF = ~0U>>1, MOD = ~0U>>1, EPS = 1e-8;

int n, m, G[MAXN][MAXN];

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d%d", &n, &m)) {
        REP(i,n)REP(j,n)G[i][j] = i==j ? 0 : 1e9;
        while (m--) {
            int x,y,z; scanf("%d%d%d", &x,&y,&z);
            G[x][y] = min(G[x][y],z);
            G[y][x] = min(G[y][x],z);
        }
        REP(k,n)REP(i,n)REP(j,n)G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
        int s,t; scanf("%d%d", &s,&t);
        printf("%d\n", G[s][t]==1e9 ? -1 : G[s][t]);
    }

    return 0;
}

































