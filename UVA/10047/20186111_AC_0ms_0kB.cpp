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
const int MAXN = 2e1+9, MAXM = 1e4+5;

#define vld(i,j) (0<=i&&i<m&&0<=j&&j<n)
const int rr[]={0,1,0,-1};
const int cc[]={1,0,-1,0};
int m,n,vis[MAXN][MAXN][4][5],kase;
char s[MAXN][MAXN];
struct node {
    int x,y,d,c,t;
};
int BFS()
{
    memset(vis,-1,sizeof(vis));
    queue<node> Q;
    REP(i,m)REP(j,n) if (s[i][j]=='S') Q.push({i,j,3,0,0});
    while (!Q.empty()) {
        node now=Q.front(); Q.pop();
        int x=now.x, y=now.y, d=now.d, c=now.c, t=now.t;
        if (s[x][y]=='T' && !c) return t;
        if (~vis[x][y][d][c]) continue;
        vis[x][y][d][c]=t;
        FOR(i,-1,1) {
            int j=(d+i+4)%4;
            int xx=x, yy=y;
            if (!i) xx+=rr[j], yy+=cc[j];
            if (vld(xx,yy) && s[xx][yy]!='#')
                Q.push({xx,yy,j,i?c:(c+1)%5,t+1});
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

    while (scanf("%d%d", &m,&n)==2 && m) {
        REP(i,m) scanf("%s", s[i]);
        if (kase++) puts("");
        printf("Case #%d\n", kase);
        int ans=BFS();
        if (ans==-1) puts("destination not reachable");
        else printf("minimum time = %d sec\n", ans);
    }

    return 0;
}


































