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
const int MAXN = 1e4+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n,a[55],mi,vis[55],kase;
vector<int> ans;
void dfs(vector<int> V)
{
    int sz=SZ(V);
    if (sz>7 || sz>=mi) return;
    bool flag=true;
    REP(i,n) if (!vis[i]) {
        bool fnd=false;
        REP(j,sz) {
            if (find(ALL(V),a[i]+V[j]) != V.end()) {
                fnd=true;
                break;
            }
        }
        if (fnd) continue;
        flag=false;
        vis[i]=1;
        V.push_back(0);
        REP(j,sz) if (a[i]+V[j]<=a[n-1]) {
            V[sz]=a[i]+V[j];
            dfs(V);
        }
        V.pop_back();
        vis[i]=0;
    }
    if (flag) {
        mi=min(mi,sz);
        ans=V;
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n)==1 && n) {
        REP(i,n) scanf("%d", &a[i]);
        sort(a,a+n);
        n=unique(a,a+n)-a;
        ans.clear();
        mi=INF;
        vector<int> V;
        V.pb(0);
        memset(vis,0,sizeof(vis));
        dfs(V);
        sort(ALL(ans));
        printf("Case %d:\n%d\n", ++kase,mi);
        REP(i,SZ(ans)-1) printf("%d ", ans[i]);
        printf("%d\n", ans[SZ(ans)-1]);
    }

    return 0;
}









































