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
const int MAXN = 1e6+9, MAXM = 2e5+9;

LL gcd(LL a, LL b){ return b==0?a:gcd(b,a%b); }
LL lcm(LL a, LL b){ return a/gcd(a,b)*b; }
LL n,e[MAXN],tot,kase;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (cin>>n && n) {
        printf("Scenario %d:\n", ++kase);
        bool fail=true;
        tot=0;
        FOR(i,1,1000000) if (n%i==0) e[tot++]=i;
        REP(i,tot) {
            FOR(j,i+1,tot-1) {
                if (e[j]>e[i]+25) break;
                FOR(k,j+1,tot-1) {
                    if (e[k]>e[i]+25) break;
                    if (lcm(lcm(e[i],e[j]),e[k])==n) {
                        printf("%lld %lld %lld\n", e[i],e[j],e[k]);
                        fail=false;
                    }
                }
            }
        }
        if (fail) puts("Such bells don't exist");
        puts("");
    }

    return 0;
}





























