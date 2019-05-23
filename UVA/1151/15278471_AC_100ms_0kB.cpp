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
const int MAXN = 1e3+5, INF = 0x3f3f3f3f, MOD = 1e9+7;

int T, n, m, u[MAXN*MAXN], v[MAXN*MAXN], w[MAXN*MAXN], r[MAXN*MAXN], p[MAXN];
bool cmp(const int i, const int j) { return w[i] < w[j]; }
int Find(int x) { return p[x] == x ? x : p[x] = Find(p[x]); }
bool Union(int i, int j) { int x = Find(i), y = Find(j); if (x != y) p[x] = y; return x != y; }
pii point[MAXN];
int c[10], a[10][MAXN], q;
inline int dist(int x, int y) { return x*x + y*y; }
inline int dis(int i, int j) { return dist(point[i].fi-point[j].fi, point[i].se-point[j].se); }
vector<int> kruskal;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    REP(kase, T) {
        if (kase) puts("");
        scanf("%d%d", &n, &q);
        REP(i,q) {
            scanf("%d%d", &a[i][0], &c[i]);
            FOR(j,1,a[i][0]) scanf("%d", &a[i][j]);
        }
        FOR(i,1,n) scanf("%d%d", &point[i].fi, &point[i].se);
        m = 0;
        FOR(i,1,n)FOR(j,i+1,n) {
            m++;
            u[m] = i, v[m] = j;
            w[m] = dis(i, j);
        }
        FOR(i,1,m) r[i] = i;
        sort(r+1, r+1+m, cmp);
        FOR(i,1,n) p[i] = i;
        kruskal.clear();
        int ans = 0;
        FOR(i,1,m) {
            int e = r[i];
            if (Union(u[e], v[e])) {
                kruskal.pb(e);
                ans += w[e];
            }
        }
        REP(k,(1<<q)) {
            int sum = 0, cnt = n-1;
            FOR(i,1,n) p[i] = i;
            REP(i,q) if (k & (1<<i)) {
                sum += c[i];
                FOR(j,2,a[i][0]) if (Union(a[i][1], a[i][j])) cnt--;
            }
            REP(i,SZ(kruskal)) {
                if (!cnt) break;
                int e = kruskal[i];
                if (Union(u[e], v[e])) {
                    cnt--;
                    sum += w[e];
                }
            }
            ans = min(ans, sum);
        }
        printf("%d\n", ans);
    }

    return 0;
}


















































































