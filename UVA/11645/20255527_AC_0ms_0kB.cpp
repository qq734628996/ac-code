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
const int MAXN = 1e3+9, MAXM = 1e4+5;

LL n,a,b,kase;
const LL DIG=1e13;
void add(LL num)
{
    b+=num;
    a+=b/DIG;
    b%=DIG;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%lld", &n)==1 && n>=0) {
        a=b=0;
        LL t=n, d=1;
        while (n>1) {
            add((n>>2)*d);
            if ((n&3)==3) add((t&(d-1))+1);
            d<<=1;
            n>>=1;
        }
        printf("Case %lld: ", ++kase);
        if (a) printf("%lld%013lld\n", a,b);
        else printf("%lld\n", b);
    }

    return 0;
}


































