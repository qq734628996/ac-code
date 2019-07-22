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
const int INF = 0x3f3f3f3f, MOD = 1000003;
const double PI = acos(-1), EPS = 1e-15;
const int MAXN = 1e6+9, MAXM = 3e3+9;

int e[MAXN][2],S[MAXN][2];
LL ans[2];
void add_int(int i, LL d)
{
    REP(j,2) ans[j]+=e[i][j]*d;
}
void add_fac(int i, LL d)
{
    REP(j,2) ans[j]+=S[i][j]*d;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    FOR(i,2,MAXN-1) {
        int j=i;
        while (j%2==0) j/=2, e[i][0]++;
        while (j%5==0) j/=5, e[i][1]++;
        REP(j,2) S[i][j]=S[i-1][j]+e[i][j];
    }
    int T; scanf("%d", &T);
    FOR(kase,1,T) {
        memset(ans,0,sizeof(ans));
        int n,r,p,q; scanf("%d%d%d%d" ,&n,&r,&p,&q);
        add_fac(n,1);
        add_fac(r,-1);
        add_fac(n-r,-1);
        add_int(p,q);
        printf("Case %d: %lld\n", kase,min(ans[0],ans[1]));
    }

    return 0;
}

































