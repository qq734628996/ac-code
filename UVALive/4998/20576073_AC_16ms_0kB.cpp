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
const int MAXN = 2e7+9, MAXM = 2e5+9;

const LL mod=1e12;
LL mul(LL a, LL b)
{
    static LL ite=(1LL<<20)-1;
    return (a*(b>>20)%mod*(1<<20)%mod+a*(b&ite)%mod)%mod;
}
LL qpow(LL a, LL b)
{
    LL res=1;
    while (b) {
        if (b&1) res=mul(res,a);
        a=mul(a,a);
        b>>=1;
    }
    return res;
}
int n,kase;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (cin>>n && n) {
        LL t=1e12,ans;
        while ((ans=qpow(n,t))!=t) {
            t=ans;
        }
        printf("Case %d: Public Key = %d Private Key = %lld\n", ++kase,n,ans);
    }

    return 0;
}





























