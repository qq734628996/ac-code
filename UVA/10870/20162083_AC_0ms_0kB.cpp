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

const int maxn=16;
int n,x,mo,a[22],f[22];
struct mat {
    LL a[maxn][maxn];
    mat(LL x=0){ memset(a,0,sizeof(a)); REP(i,n) a[i][i]=x; }
    mat operator*(const mat& T) const {
        mat res;
        REP(i,n)REP(k,n) {
            LL r=a[i][k];
            REP(j,n) res.a[i][j]+=r*T.a[k][j];
        }
        REP(i,n)REP(j,n) res.a[i][j]%=mo;
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
    void print(){
        REP(i,n){
            REP(j,n) printf("%lld\t", a[i][j]);
            puts("");
        }
        puts("");
    }
};

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d%d", &n,&x,&mo)==3) {
        if (n==0 && x==0 && mo==0) break;
        REP(i,n) scanf("%d", &a[i]), a[i]%=mo;
        REP(i,n) scanf("%d", &f[i]), f[i]%=mo;
        if (x<=n) { printf("%d\n", f[x-1]); continue; }
        mat M;
        REP(i,n-1) M.a[i][i+1]=1;
        REP(j,n) M.a[n-1][j]=a[n-1-j];
        M=M^(x-n);
        LL ans=0;
        REP(j,n) ans+=M.a[n-1][j]*f[j];
        printf("%lld\n", ans%mo);
    }

    return 0;
}




































