#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n) printf("%d%c", A[i],i==n-1?'\n':' '); }
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
const int MAXN = 1e6+9, MAXM = 3e3+9;

int n,K,mo;
int qpow(int a, int b)
{
    int x=1;
    for (int t=a; b; b>>=1, t=t*t%mo) if (b&1) x=x*t%mo;
    return x;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    FOR(kase,1,T) {
        scanf("%d%d%d", &n,&K,&mo);
        int ans=0;
        REP(i,n) {
            int x; scanf("%d", &x);
            ans+=x%mo;
        }
        ans%=mo;
        ans=(ans*qpow(n,K-1))%mo;
        ans=((LL)ans*K)%mo;
        printf("Case %d: %d\n", kase,ans);
    }

    return 0;
}


































