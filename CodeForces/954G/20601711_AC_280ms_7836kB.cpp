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
const int MAXN = 5e5+9, MAXM = 2e5+9;

LL n,R,k,a[MAXN],b[MAXN];
bool jdg(LL x)
{
    FOR(i,1,n) b[i]=a[i];
    LL sum=0,kk=k;
    FOR(i,1,n) {
        sum+=b[i];
        if (sum<x) {
            if (x-sum>kk) return false;
            kk-=x-sum;
            b[min(n,i+2*R)+1]-=x-sum;
            sum=x;
        }
    }
    return true;
}

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%lld%lld%lld", &n,&R,&k);
    FOR(i,1,n) {
        LL x; scanf("%lld", &x);
        LL l=max(1LL,i-R), r=min(n,i+R);
        a[l]+=x, a[r+1]-=x;
    }
    LL l=0,r=2e18,ans;
    while (l<=r) {
        LL m=l+(r-l)/2;
        if (jdg(m)) ans=m, l=m+1;
        else r=m-1;
    }
    printf("%lld\n", ans);

    return 0;
}



























