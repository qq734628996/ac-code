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
const int INF = 0x3f3f3f3f, MOD = 998244353;
const double PI = acos(-1), EPS = 1e-15;
const int MAXN = 4e6+9, MAXM = 2e5+9;

void ex_gcd(LL a, LL b, LL& d, LL& x, LL& y)
{
    if (!b) d=a, x=1, y=0;
    else ex_gcd(b,a%b,d,y,x), y-=x*(a/b);
}
bool jdg(LL a, LL b, LL c)
{
    LL d,x,y;
    ex_gcd(a,b,d,x,y);
    if (c%d) return false;
    x*=c/d;
    y*=c/d;
    a/=d;
    b/=d;
    LL l=floor((double)(-x)/b), r=ceil((double)y/a);
    return l+1<=r-1;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        int a,b,c,d; scanf("%d%d%d%d", &a,&b,&c,&d);
        if ((c%a==0 && d%b==0)
            || (c%b==0 && d%a==0)
            || (c%a==0 && c%b==0 && jdg(a,b,d))
            || (d%a==0 && d%b==0 && jdg(a,b,c))) puts("YES");
        else puts("NO");
    }

    return 0;
}




























