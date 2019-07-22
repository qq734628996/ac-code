#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n-1) printf("%d ", A[i]); printf("%d\n", A[n-1]); }
#define SHOW2(A,m,n) { REP(i,m) { REP(j,n-1) printf("%d ", A[i][j]); printf("%d\n", A[i][n-1]); } }
#define pb push_back
#define fi first
#define se second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)((x).size())
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const int INF = 0x3f3f3f3f, MOD = 1000000007;
const double PI = acos(-1), EPS = 1e-15;
const int MAXN = 1e2+9, MAXM = 3e3+9;

int m,n,r1,c1,r2,c2,a[MAXN][MAXN][2],d[MAXN][MAXN][4][2],kase;
struct node {
    int x,y,dir,flag,du;
    bool operator<(const node& o) const { return du>o.du; }
};
const int r[]={0,1,0,-1};
const int c[]={1,0,-1,0};
const int ni[]={0,0,0,-1};
const int nj[]={0,0,-1,0};
const int nk[]={0,1,0,1};
bool vld(int i, int j, int k)
{
    if (k) return 1<=i&&i<m&&1<=j&&j<=n&&a[i][j][k];
    return 1<=i&&i<=m&&1<=j&&j<n&&a[i][j][k];
}
int dij()
{
    memset(d,INF,sizeof(d));
    priority_queue<node> pq;
    pq.push({r1,c1,-1,1,0});
    while (!pq.empty()) {
        node t=pq.top(); pq.pop();
        int x=t.x, y=t.y, dir=t.dir, flag=t.flag, du=t.du;
        if (flag) {
            REP(ndir,4) {
                int i=x+ni[ndir], j=y+nj[ndir], k=nk[ndir];
                if (vld(i,j,k)) {
                    int xx=x+r[ndir], yy=y+c[ndir], w=2*a[i][j][k];
                    int& dv=d[xx][yy][ndir][1];
                    if (dv>du+w) {
                        dv=du+w;
                        pq.push({xx,yy,ndir,1,dv});
                    }
                }
            }
        } else if (~dir) {
            int i=x+ni[dir], j=y+nj[dir], k=nk[dir];
            if (vld(i,j,k)) {
                int xx=x+r[dir], yy=y+c[dir], w=2*a[i][j][k];
                int& dv=d[xx][yy][dir][1];
                if (dv>du+w) {
                    dv=du+w;
                    pq.push({xx,yy,dir,1,dv});
                }
            }
        }
        if (dir==-1) continue;
        int i=x+ni[dir], j=y+nj[dir], k=nk[dir];
        if (vld(i,j,k)) {
            int xx=x+r[dir], yy=y+c[dir], w=a[i][j][k];
            int& dv=d[xx][yy][dir][0];
            if (dv>du+w) {
                dv=du+w;
                pq.push({xx,yy,dir,0,dv});
            }
        }
    }
    int ans=INF;
    REP(i,4)ans=min(ans,d[r2][c2][i][1]);
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d%d%d%d%d", &m,&n,&r1,&c1,&r2,&c2)==6 && m) {
        FOR(i,1,m) {
            FOR(j,1,n-1) scanf("%d", &a[i][j][0]);
            if (i<m) FOR(j,1,n) scanf("%d", &a[i][j][1]);
        }
        int ans=dij();
        printf("Case %d: ", ++kase);
        if (ans==INF) puts("Impossible");
        else printf("%d\n", ans);
    }

    return 0;
}

































