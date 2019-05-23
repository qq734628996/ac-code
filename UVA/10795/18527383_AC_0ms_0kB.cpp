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

LL f(int* A, int i, int goal)
{
    if (!i) return 0;
    if (A[i]==goal) return f(A,i-1,goal);
    return f(A,i-1,6-A[i]-goal)+(1LL<<(i-1));
}
int n,a[2][66],kase;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n)==1 && n) {
        REP(i,2)FOR(j,1,n) scanf("%d", &a[i][j]);
        int i=n;
        while (1<=i && a[0][i]==a[1][i]) i--;
        LL ans=0;
        if (1<=i) {
            int goal=6-a[0][i]-a[1][i];
            ans=f(a[0],i-1,goal)+f(a[1],i-1,goal)+1;
        }
        printf("Case %d: %lld\n", ++kase,ans);
    }

    return 0;
}












































