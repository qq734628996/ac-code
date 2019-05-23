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

int n, x, y, vis[10], kase, ok;
char a[10], b[10];
void dfs(int cur)
{
    if (cur == 5) {
        sscanf(b, "%d", &y);
        x = n * y;
        sprintf(a, "%d", x);
        if (strlen(a) == 5) {
            int _vis[10] = {0};
            REP(i,5) _vis[a[i]-'0'] = _vis[b[i]-'0'] = 1;
            REP(i,10) if (!_vis[i]) return;
            printf("%s / %s = %d\n", a, b, n);
            ok = 1;
        }
    } else {
        REP(i,10)if(!vis[i]) {
            vis[i] = 1;
            b[cur] = i + '0';
            dfs(cur+1);
            vis[i] = 0;
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n), n) {
        if (kase++) puts("");
        ok = 0;
        dfs(0);
        if (!ok) printf("There are no solutions for %d.\n", n);
    }

    return 0;
}

































