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
const int MAXN = 1e6+9, MAXM = 3e3+9;

double Mod1(double x)
{
    while (x>1e66) x/=10;
    return x;
}
double powMod1(LL x, LL e)
{
    double res=1;
    for (double t=x; e; t=Mod1(t*t), e/=2) {
        if (e&1) res=Mod1(res*t);
    }
    return res;
}
LL Mod2(LL x)
{
    return x%1000;
}
LL powMod2(LL x, LL e)
{
    LL res=1;
    for (LL t=x; e; t=Mod2(t*t), e>>=1) {
        if (e&1) res=Mod2(res*t);
    }
    return res;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    FOR(kase,1,T) {
        LL x,y; scanf("%lld%lld", &x,&y);
        char s[1024];
        sprintf(s,"%.0f",powMod1(x,y));
        s[3]='\0';
        LL res1; sscanf(s,"%lld",&res1);
        printf("Case %d: %lld %03lld\n", kase,res1,powMod2(x,y));
    }

    return 0;
}































