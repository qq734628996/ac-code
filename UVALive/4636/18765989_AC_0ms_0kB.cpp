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
const int MAXN = 1e5+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int w,d,a[12],b[12],vis[12];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d", &w,&d)==2 && w) {
        REP(i,w) scanf("%d", &a[i]);
        REP(j,d) scanf("%d", &b[j]);
        memset(vis,0,sizeof(vis));
        sort(b,b+d,greater<int>());
        int ans=0;
        REP(i,w) ans+=a[i];
        REP(j,d) {
            bool flag=false;
            PER(i,w) if (!vis[i] && a[i]==b[j]) {
                vis[i]=1;
                flag=true;
                break;
            }
            if (!flag) ans+=b[j];
        }
        printf("%d\n", ans);
    }

    return 0;
}









































