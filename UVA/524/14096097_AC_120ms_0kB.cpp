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
const int MAXN  = 50, INF = ~0U>>1, MOD = ~0U>>1;

int prime[] = {0,0,2,3,0,5,0,7,0,0,0,11,0,13,0,0,0,17,0,19,0,0,0,23,0,0,0,0,0,29,0,31,0};
int n, a[20], kase, vis[20];

void dfs(int cur)
{
    if (cur == n) {
        if (prime[a[n-1] + a[0]]) SHOW1(a, n)
        return;
    }
    FOR(i,2,n) {
        if (!vis[i] && prime[i+a[cur-1]]) {
            vis[i] = 1;
            a[cur] = i;
            dfs(cur + 1);
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

    a[0] = 1;
    while (~scanf("%d", &n)) {
        if (kase) puts("");
        printf("Case %d:\n", ++kase);
        dfs(1);
    }

    return 0;
}

































