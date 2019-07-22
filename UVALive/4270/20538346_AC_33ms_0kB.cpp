#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n) cout<<A[i]<<(i==n-1?'\n':' '); }
#define SHOW2(A,m,n) { REP(j,m) SHOW1(A[j],n) }
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
const int MAXN = 1e5+9, MAXM = 2e5+9;

LL x,n,r,kase;
LL ex_gcd(LL a, LL b, LL& d, LL& x, LL& y)
{
    if (!b) d=a, x=1, y=0;
    else ex_gcd(b,a%b,d,y,x), y-=x*(a/b);
}
set<LL> fac;
void getfac(LL n)
{
    fac.clear();
    int m=sqrt(n+0.5);
    FOR(i,1,m) if (n%i==0) {
        fac.insert(i);
        fac.insert(n/i);
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (cin>>x>>n>>r) {
        if (!x && !n && !r) break;
        getfac(n);
        set<LL> ans;
        for (auto& a:fac) {
            LL b=n/a, c=2*r, d,x,y;
            ex_gcd(a,b,d,x,y);
            if (c%d==0) {
                x*=c/d;
                LL bb=b/d;
                LL st=floor(((double)r-x*a-n)/(a*bb))+1;
                LL ed=floor(((double)r-x*a)/(a*bb));
                FOR(k,st,ed) {
                    ans.insert(r-x*a-k*a*bb);
                }
            }
        }
        printf("Case %lld:", ++kase);
        for (auto& i:ans) printf(" %lld", i);
        puts("");
    }

    return 0;
}






























