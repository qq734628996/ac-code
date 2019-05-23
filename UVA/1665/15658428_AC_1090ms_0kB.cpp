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
const int MAXN = 1e3+5, MAXM = 1e6+5, INF = 0x3f3f3f3f, MOD = 998244353;

int T, n, m, tot, a[MAXN][MAXN], vis[MAXN][MAXN], w[MAXM];
int p[MAXM], r[MAXM], q, qry[MAXM], ans[MAXM];
inline int ID(int i, int j) { return i*n+j; }
bool cmp(const int i, const int j) { return w[i] > w[j]; }
int Find(int x) { return p[x] == x ? x : p[x] = Find(p[x]); }
bool Union(int i, int j) { int x = Find(i), y = Find(j); if (x != y) p[x] = y; return x != y; }
void init()
{
    REP(i,m)REP(j,n) vis[i][j] = 0;
    REP(i,tot) p[i] = i, r[i] = i;
    sort(r, r+tot, cmp);
}
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
inline bool vld(int i, int j) { return 0<=i && i<m && 0<=j && j<n; }

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &m, &n);
        REP(i,m)REP(j,n) scanf("%d", &a[i][j]);
        scanf("%d", &q);
        REP(i,q) scanf("%d", &qry[i]);
        REP(i,m)REP(j,n) w[ID(i,j)] = a[i][j];
        tot = m*n;
        init();
        int cnt = 0, i = 0;
        PER(j,q) {
            for (; i < tot && w[r[i]] > qry[j]; i++) {
                int e = r[i];
                int x = e/n, y = e%n;
                vis[x][y] = 1;
                cnt++;
                REP(k,4) {
                    int xx = x+dr[k], yy = y+dc[k];
                    if (vld(xx, yy) && vis[xx][yy] && Union(ID(x,y), ID(xx,yy))) cnt--;
                }
            }
            ans[j] = cnt;
        }
        REP(i,q) printf("%d ", ans[i]);
        puts("");
    }

    return 0;
}


















































































