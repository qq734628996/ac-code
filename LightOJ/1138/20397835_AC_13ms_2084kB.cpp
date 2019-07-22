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
const int MAXN = 5e5+9, MAXM = 3e3+9;

int f(int n)
{
    int ans=0;
    while (n) {
        ans+=n/5;
        n/=5;
    }
    return ans;
}
int g(int n)
{
    int l=1,r=1e9+9;
    while (l<r) {
        int m=(l+r)/2;
        if (f(m)<=n) l=m+1;
        else r=m;
    }
    if (f(l-5)==n) return l-5;
    return -1;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    FOR(kase,1,T) {
        int n; scanf("%d", &n);
        printf("Case %d: ", kase);
        int ans=g(n);
        if (ans==-1) puts("impossible");
        else printf("%d\n", ans);
    }

    return 0;
}


































