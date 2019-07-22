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
const int MAXN = 5e3+9, MAXM = 3e3+9;

int n,a[MAXN],b[MAXN],d[MAXN][MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n)==1) {
        memset(d,0,sizeof(d));
        map<int,int> mp;
        REP(i,n) scanf("%d", &a[i]), mp[a[i]]++;
        int ans=1;
        sort(a,a+n);
        n=unique(a,a+n)-a;
        REP(i,n) {
            b[i]=mp[a[i]];
            ans=max(ans,b[i]);
        }
        FOR(i,1,n-1) {
            REP(j,i) {
                int t=a[i]-a[j];
                int pos=lower_bound(a,a+n,a[j]-t)-a;
                if (pos>=0 && a[pos]==a[j]-t) d[i][j]=d[j][pos]+1;
                else d[i][j]=2;
                ans=max(ans,d[i][j]);
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
































