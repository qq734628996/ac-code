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
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const int INF = 0x3f3f3f3f, MOD = 1000000007;
const double EPS = 1e-14;
const int MAXN = 5e4+9, MAXM = 1e4+5;

typedef long double ld;
ld logF[MAXN];
ld logC(int n, int m){ return logF[n]-logF[m]-logF[n-m]; }

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    FOR(i,2,MAXN-1) logF[i]=logF[i-1]+log2(i);
    int T; scanf("%d", &T);
    FOR(kase,1,T) {
        int n; scanf("%d", &n);
        ld ans=0;
        REP(i,n) {
            ld x; cin>>x;//scanf("%Lf", &x);
            ans+=(x<0?-1:1)*pow(2, logC(n-1,i)+log2(fabs(x))-(n-1));
        }
        printf("Case #%d: ", kase);
        cout<<setiosflags(ios::fixed)<<setprecision(3)<<ans<<endl;
    }

    return 0;
}




































