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
const double EPS = 1e-14;
const int MAXN = 1e3+9, MAXM = 1e4+5;

#define vld(i,j) (0<=i&&i<m&&0<=j&&j<n)
const int r[]={0,1,0,-1};
const int c[]={1,0,-1,0};
int m,n,vis[MAXN][MAXN],fire[MAXN][MAXN];
char s[MAXN][MAXN];
struct node {
    int x,y,t;
};
void init()
{
    queue<node> Q;
    REP(i,m)REP(j,n) if (s[i][j]=='F') Q.push({i,j,0});
    while (!Q.empty()) {
        node now=Q.front(); Q.pop();
        int x=now.x, y=now.y, t=now.t;
        if (~fire[x][y]) continue;
        fire[x][y]=t;
        REP(i,4) {
            int xx=x+r[i], yy=y+c[i];
            if (vld(xx,yy) && s[xx][yy]!='#')
                Q.push({xx,yy,t+1});
        }
    }
}
int BFS()
{
    queue<node> Q;
    REP(i,m)REP(j,n) if (s[i][j]=='J') { Q.push({i,j,0}); break; }
    while (!Q.empty()) {
        node now=Q.front(); Q.pop();
        int x=now.x, y=now.y, t=now.t;
        if (x==0 || y==0 || x==m-1 || y==n-1) return t+1;
        if (~vis[x][y]) continue;
        vis[x][y]=t;
        REP(i,4) {
            int xx=x+r[i], yy=y+c[i];
            if (vld(xx,yy) && s[xx][yy]!='#' && (fire[xx][yy]==-1 || fire[xx][yy]>t+1))
                Q.push({xx,yy,t+1});
        }
    }
    return -1;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &m,&n);
        REP(i,m) scanf("%s", s[i]);
        REP(i,m)REP(j,n) vis[i][j]=fire[i][j]=-1;
        init();
        int ans=BFS();
        if (ans==-1) puts("IMPOSSIBLE");
        else printf("%d\n", ans);
    }

    return 0;
}


































