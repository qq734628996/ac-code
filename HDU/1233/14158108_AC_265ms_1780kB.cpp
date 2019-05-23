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
const int MAXN  = 5e3, INF = ~0U>>1, MOD = ~0U>>1;

int n, m, u[MAXN], v[MAXN], w[MAXN], r[MAXN], p[MAXN];

int cmp(const int i, const int j) { return w[i] < w[j]; }
int Find(int x) { return p[x] == x ? x : p[x] = Find(p[x]); }
int Kruskal()
{
    int ans = 0;
    FOR(i,1,n) p[i] = i;
    FOR(i,1,m) r[i] = i;
    sort(r+1, r+m+1, cmp);
    FOR(i,1,m) {
        int e = r[i]; int x = Find(u[e]); int y = Find(v[e]);
        if (x != y) { ans += w[e]; p[x] = y; }
    }
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n), n) {
        m = n*(n-1)/2;
        FOR(i,1,m) scanf("%d%d%d", &u[i], &v[i], &w[i]);
        printf("%d\n", Kruskal());
    }

    return 0;
}
