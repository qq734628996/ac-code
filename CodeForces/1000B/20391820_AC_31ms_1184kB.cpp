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
const int MAXN = 1e5+9, MAXM = 3e3+9;


int n,m,a[MAXN],s1[MAXN],s2[MAXN];

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d", &n,&m)==2) {
        FOR(i,1,n) scanf("%d",&a[i]);
        a[n+1]=m;
        FOR(i,1,n+1) {
            if (i&1) {
                s1[i]=s1[i-1]+a[i]-a[i-1];
                s2[i]=s2[i-1];
            } else {
                s1[i]=s1[i-1];
                s2[i]=s2[i-1]+a[i]-a[i-1];
            }
        }
        int ans=s1[n+1];
        FOR(i,1,n) {
            int now;
            if (a[i]-a[i-1]>1 || a[i+1]-a[i]>1) {
                if (i&1) now=s1[i]+s2[n+1]-s2[i]-1;
                else now=s1[i]+s2[n+1]-s2[i]+1;
            }
            ans=max(now,ans);
        }
        printf("%d\n", ans);
    }

    return 0;
}


































