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
const int MAXN = 1e2+5, MAXM = 5e3+5, INF = 0x3f3f3f3f, MOD = 10007;

int n,a[22];
LL f[1<<16],g[1<<16];
void read(int& x, int n)
{
    char s[22]; scanf("%s", s);
    x=0;
    PER(i,n) x=x*2+s[i]-'0';
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    FOR(kase,1,T) {
        scanf("%d", &n);
        read(a[n],n);
        REP(i,n) read(a[i],n);
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        f[0]=1;
        g[0]=a[n];
        REP(i,(1<<n)) {
            REP(j,n) if ((g[i]>>j&1) && !(i>>j&1)) {
                int k=(i|(1<<j));
                f[k]+=f[i];
                g[k]=(g[i]|a[j]);
            }
        }
        printf("Case %d: %lld\n", kase,f[(1<<n)-1]);
    }

    return 0;
}






































