#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n) cout<<A[i]<<(i==n-1?'\n':' '); }
#define SHOW2(A,m,n) { REP(j,m) SHOW1(A[j],n) }
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
const int MAXN = 3e2+9, MAXM = 2e3+9;

int nx,ny,g[MAXN][MAXN];
int linker[MAXN],lx[MAXN],ly[MAXN];
int slack[MAXN];
bool visx[MAXN],visy[MAXN];
bool dfs(int x)
{
    visx[x]=true;
    REP(y,ny) {
        if (visy[y]) continue;
        int tmp=lx[x]+ly[y]-g[x][y];
        if (!tmp) {
            visy[y]=1;
            if (linker[y]==-1 || dfs(linker[y])) {
                linker[y]=x;
                return true;
            }
        } else if (slack[y]>tmp) slack[y]=tmp;
    }
    return false;
}
int KM()
{
    memset(linker,-1,sizeof(linker));
    memset(ly,0,sizeof(ly));
    REP(i,nx) {
        lx[i]=-INF;
        REP(j,ny) lx[i]=max(lx[i],g[i][j]);
    }
    REP(x,nx) {
        REP(i,ny) slack[i]=INF;
        while (true) {
            memset(visx,0,sizeof(visx));
            memset(visy,0,sizeof(visy));
            if (dfs(x)) break;
            int d=INF;
            REP(i,ny) if (!visy[i] && d>slack[i]) d=slack[i];
            REP(i,nx) if (visx[i]) lx[i]-=d;
            REP(i,ny) {
                if (visy[i]) ly[i]+=d;
                else slack[i]-=d;
            }
        }
    }
    int ans=0;
    REP(i,ny) if (~linker[i]) ans+=g[linker[i]][i];
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int n;
    while (scanf("%d", &n)==1) {
        memset(g,0,sizeof(g));
        REP(i,n)REP(j,n) scanf("%d", &g[i][j]);
        nx=ny=n;
        printf("%d\n", KM());
    }

    return 0;
}
































