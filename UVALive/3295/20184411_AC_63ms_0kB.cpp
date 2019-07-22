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
const int MAXN = 1e3+9, MAXM = 1e4+5;

int g[MAXN][MAXN];
int gcd(int a, int b){ return b==0?a:gcd(b,a%b); }

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    FOR(i,1,1000)FOR(j,1,1000) g[i][j]=g[j][i]=gcd(i,j);
    LL m,n,kase=0;
    while (scanf("%lld%lld", &m,&n)==2 && m) {
        LL mn=(m+1)*(n+1);
        LL ans1=mn*(mn-1)*(mn-2)/6;
        LL ans2=(m+1)*(n+1)*n*(n-1)/6+(n+1)*(m+1)*m*(m-1)/6;
        LL ans3=0;
        FOR(i,1,m)FOR(j,1,n) {
            ans3+=(m+1-i)*(n+1-j)*(g[i][j]-1);
        }
        printf("Case %lld: %lld\n", ++kase,ans1-ans2-2*ans3);
    }

    return 0;
}



































