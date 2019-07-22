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
const int MAXN = 1e3+9, MAXM = 3e3+9;

const int r[]={0,1,0,-1};
const int c[]={1,0,-1,0};
int n,K,vis[MAXN][MAXN][12];
#define vld(i,j) (0<=i&&i<n&&0<=j&&j<n)
char s[MAXN][MAXN];
struct node{
    int x,y,k;
};
int bfs()
{
    memset(vis,-1,sizeof(vis));
    queue<node> Q;
    Q.push({0,0,K-(s[0][0]=='#')});
    vis[0][0][K-(s[0][0]=='#')]=0;
    while (!Q.empty()) {
        node now=Q.front(); Q.pop();
        int x=now.x, y=now.y, k=now.k;
        int t=vis[x][y][k];
        if (x==n-1 && y==n-1) return t;
        REP(i,4) {
            int xx=x+r[i], yy=y+c[i];
            if (vld(xx,yy)) {
                if (s[xx][yy]=='.') {
                    if (vis[xx][yy][k]==-1) {
                        vis[xx][yy][k]=t+1;
                        Q.push({xx,yy,k});
                    }
                } else if (k>0) {
                    if (vis[xx][yy][k-1]==-1) {
                        vis[xx][yy][k-1]=t+1;
                        Q.push({xx,yy,k-1});
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d", &n,&K)==2) {
        REP(i,n) scanf("%s", s[i]);
        printf("%d\n", bfs());
    }

    return 0;
}
































