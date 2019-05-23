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
const int MAXN = 1e3+5, MAXM = 5e3+5, INF = 0x3f3f3f3f, MOD = 10007;

int n;
pii a[MAXN];
int gcd(int a, int b) { return b==0?a:gcd(b,a%b); }
map<int,int> dp;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n)==1) {
        REP(i,n) scanf("%d", &a[i].fi);
        REP(i,n) scanf("%d", &a[i].se);
        dp.clear();
        dp[0]=0;
        REP(i,n) {
            int l=a[i].fi, c=a[i].se;
            for (auto& i:dp) {
                int x=gcd(i.fi,l);
                int y=i.se+c;
                if (dp[x] && dp[x]<y) continue;
                dp[x]=y;
            }
        }
        if (!dp[1]) puts("-1");
        else printf("%d\n", dp[1]);
    }

    return 0;
}





































