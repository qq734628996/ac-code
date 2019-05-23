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
typedef pair<int, int> pii;
const int MAXN = 1e2+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n,vis[22],now[2],step[2];
const int dir[]={1,-1};

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d%d", &n,&step[0],&step[1])==3 && n+step[0]+step[1]) {
        REP(i,2) if (step[i]>n) step[i]%=n;
        now[0]=n-1;
        now[1]=0;
        memset(vis,0,sizeof(vis));
        int cnt=0;
        REP(k,n) {
            REP(i,2)REP(j,step[i]) while (vis[now[i]=(now[i]+dir[i]+n)%n]);
            if (k) printf(",");
            printf("%3d", now[0]+1),cnt++;
            if (now[0]!=now[1]) printf("%3d", now[1]+1),cnt++;
            if (cnt==n) break;
            REP(i,2) vis[now[i]]=1;
        }
        puts("");
    }

    return 0;
}














































