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
const int MAXN = 1e4+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int m,n,a[11],b[11],c[11],d[11],p[11];
bool jdg()
{
    memcpy(c,b,sizeof(b));
    sort(c,c+m);
    FOR(i,2,m) {
        REP(j,m) d[j]=b[j]*i;
        REP(j,m-1) {
            d[j+1]+=d[j]/n;
            d[j]%=n;
        }
        sort(d,d+m);
        if (memcmp(c,d,sizeof(int)*m)) return false;
    }
    return true;
}
void solve()
{
    bool fail=true;
    FOR(i,1,n-1) {
        a[0]=b[0]=i;
        FOR(j,2,m) a[j-1]=(i*j)%n;
        FOR(j,1,m-1) p[j]=j;
        do {
            FOR(j,1,m-1) b[j]=a[p[j]];
            if (jdg()) {
                fail=false;
                ROF(j,1,m-1) printf("%d ", b[j]);
                printf("%d\n", b[0]);
                break;
            }
        } while (next_permutation(p+1,p+m));
        if (!fail) break;
    }
    if (fail) puts("Not found.");
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d", &m,&n)==2 && m) {
        solve();
    }

    return 0;
}









































