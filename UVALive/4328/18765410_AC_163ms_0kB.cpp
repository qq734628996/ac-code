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
typedef pair<int, int> pii;
const int MAXN = 1e5+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n;
struct node {
    LL s,t,m;
    bool operator<(const node& o) const {
        return m<o.m || (m==o.m && s<o.s);
    }
} a[MAXN];
bool jdg()
{
    sort(a,a+n);
    LL now=0;
    REP(i,n) {
        LL s=a[i].s, t=a[i].t, m=a[i].m;
        if (now<s) now=s;
        if (now>m) return false;
        now+=t-m;
    }
    return true;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n)==1 && n) {
        REP(i,n) {
            scanf("%lld%lld", &a[i].s,&a[i].t);
            a[i].m=a[i].t-(a[i].t-a[i].s)/2-1;
        }
        puts(jdg()?"YES":"NO");
    }

    return 0;
}









































