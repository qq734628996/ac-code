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
const int MAXN = 1e3+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n,a[22],ans[MAXN];
bool dfs(int d, int maxd)
{
    if (a[d]==n) return true;
    if (d==maxd) return false;
    int maxv=*max_element(a,a+d+1);
    if ((maxv<<(maxd-d))<n) return false;
    ROF(i,0,d) {
        a[d+1]=a[d]+a[i];
        if (dfs(d+1,maxd)) return true;
        a[d+1]=a[d]-a[i];
        if (dfs(d+1,maxd)) return true;
    }
    return false;
}
int solve(int x)
{
    if (x==1) return 0;
    a[0]=1;
    for (int maxd=1; ; maxd++) {
        if (dfs(0,maxd)) return maxd;
    }
    return -1;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n)==1 && n) {
        printf("%d\n", solve(n));
    }

    return 0;
}









































