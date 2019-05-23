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
const int MAXN = 1e6+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

typedef pair<double, double> pdd;
int n,w[11],vis[111],cnt[111];
double width,sum[111];
vector<pdd> tree[111];
void dfs(int s)
{
    if (vis[s]) return;
    vis[s]=1;
    if (cnt[s]==1) {
        tree[s].pb(pdd(0,0));
        return;
    }
    for (int L=(s-1)&s; L; L=(L-1)&s) {
        int R=s^L;
        double d1=sum[R]/sum[s];
        double d2=sum[L]/sum[s];
        dfs(L); dfs(R);
        REP(i,SZ(tree[L]))REP(j,SZ(tree[R])) {
            double l=max(tree[L][i].fi+d1, tree[R][j].fi-d2);
            double r=max(tree[R][j].se+d2, tree[L][i].se-d1);
            if (l+r<width) tree[s].pb(pdd(l,r));
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%lf%d", &width,&n);
        REP(i,n) scanf("%d", &w[i]);
        memset(sum,0,sizeof(sum));
        memset(cnt,0,sizeof(cnt));
        REP(i,(1<<n)) {
            tree[i].clear();
            REP(j,n) if (i&(1<<j)) {
                sum[i]+=w[j];
                cnt[i]++;
            }
        }
        int rt=(1<<n)-1;
        memset(vis,0,sizeof(vis));
        dfs(rt);
        double ans=-1;
        REP(i,SZ(tree[rt])) ans=max(ans,tree[rt][i].fi+tree[rt][i].se);
        printf("%.10f\n", ans);
    }

    return 0;
}









































