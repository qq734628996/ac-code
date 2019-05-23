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
const int MAXN  = 1e3+5, INF = ~0U>>1, MOD = ~0U>>1;




char s[MAXN][MAXN];
int m, n, cnt;
void dfs(int _i, int _j)
{
    s[_i][_j] = '*';
    FOR(i,-1,1)FOR(j,-1,1)if(0<=_i+i && _i+i<=m && 0<=_j+j && _j+j<=n && s[_i+i][_j+j] == '@') dfs(_i+i,_j+j);
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL


    while (scanf("%d%d", &m, &n), m) {
        REP(i,m)scanf("%s", s[i]);
        cnt = 0;
        REP(i,m)REP(j,n)if (s[i][j] == '@') { dfs(i,j); cnt++; }
        printf("%d\n", cnt);
    }





























































    return 0;
}
