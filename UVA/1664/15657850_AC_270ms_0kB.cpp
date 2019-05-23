#include <bits/stdc++.h>
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
const int MAXN = 2e5+5, MAXM = 5e2+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n, m, u[MAXN], v[MAXN], w[MAXN], a[MAXN], p[MAXN], num[MAXN];
LL sum[MAXN];
bool cmp(const int i, const int j) { return w[i] > w[j]; }
int Find(int x) { return p[x] == x ? x : p[x] = Find(p[x]); }
void Union(int i, int j, int W)
{
    int x = Find(i), y = Find(j);
    p[y] = x;
    sum[x] = max(sum[x]+(LL)num[y]*W, sum[y]+(LL)num[x]*W);
    num[x] += num[y];
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d", &n)) {
        m = n-1;
        REP(i,m) scanf("%d%d%d", &u[i], &v[i], &w[i]);
        REP(i,m) a[i] = i;
        sort(a, a+m, cmp);
        FOR(i,1,n) p[i] = i, sum[i] = 0, num[i] = 1;
        REP(i,m) {
            int e = a[i];
            Union(u[e], v[e], w[e]);
        }
        printf("%lld\n", sum[Find(1)]);
    }

    return 0;
}


















































































