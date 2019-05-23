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
const int MAXN  = 2e2+5, INF = ~0U>>1, MOD = ~0U>>1;


char G[52][52], s[10], vis[52];
int n;
inline int id(int i) { i <<= 1; return (s[i]-'A')*2+(s[i+1]=='+'); }

bool dfs(int i)
{
    vis[i] = -1;
    REP(j,52)if(G[i][j] && (vis[j]<0 || (!vis[j] && !dfs(j)))) return false;
    vis[i] = 1;
    return true;
}

bool toposort()
{
    memset(vis,0,sizeof(vis));
    REP(i,52)if(!vis[i] && !dfs(i)) return false;
    return true;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d", &n)) {
        memset(G,0,sizeof(G));
        REP(i,n) {
            scanf("%s", s);
            REP(i,4)REP(j,4)if(i != j && s[i<<1] != '0' && s[j<<1] != '0')
                G[id(i)][id(j)^1] = 1;
        }
        puts(toposort() ? "bounded" : "unbounded");
    }





    return 0;
}






















