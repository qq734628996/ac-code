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
const int INF = 0x3f3f3f3f, MOD = 100000007;
const int MAXN = 1e3+29, MAXM = 1e4+5;

int n,m,d,k,a[555];
struct mat {
    static const int maxn=505;
    LL a[maxn];
    LL& operator()(int i, int j) { return a[(j-i+n)%n]; }
    mat(LL x=0){ memset(a,0,sizeof(a)); a[0]=x; }
    mat operator*(mat& T) {
        mat res;
        REP(i,1)REP(k,n) {
            LL r=(*this)(i,k);
            REP(j,n) res(i,j)+=r*T(k,j);
        }
        REP(i,1)REP(j,n) res(i,j)%=m;
        return res;
    }
    mat operator^(LL x) const {
        mat res(1), bas{*this};
        for (; x; x>>=1) {
            if (x&1) res=res*bas;
            bas=bas*bas;
        }
        return res;
    }
    void print() {
        REP(i,n) printf("%lld ", a[i]);
        puts("");
    }
};

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d%d%d", &n,&m,&d,&k)==4) {
        REP(i,n) scanf("%d", &a[i]);
        mat M(1);
        REP(i,d) M.a[1+i]=M.a[n-1-i]=1;
        M=M^k;
        REP(j,n) {
            LL ans=0;
            REP(i,n) ans+=M(i,j)*a[i];
            printf("%lld%c", ans%m,j==n-1?'\n':' ');
        }
    }

    return 0;
}




































