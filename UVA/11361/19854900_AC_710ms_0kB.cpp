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
const int MAXN = 1e4+5, MAXM = 5e3+5, INF = 0x3f3f3f3f, MOD = 1000000000;

int a[12],k;
LL d[12][100][MAXN];
LL dp(int pos, int rmd1, int rmd2, bool limit)
{
    rmd2%=k;
    if (pos==-1) return !(rmd1%k) && !rmd2;
    LL& r=d[pos][rmd1][rmd2];
    if (!limit && ~r) return r;
    int up=limit?a[pos]:9;
    LL ans=0;
    FOR(i,0,up) ans+=dp(pos-1,rmd1+i,rmd2*10+i,limit&&i==up);
    if (!limit) r=ans;
    return ans;
}
LL solve(int x)
{
    int cnt=0;
    while (x) {
        a[cnt++]=x%10;
        x/=10;
    }
    return dp(cnt-1,0,0,true);
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        memset(d,-1,sizeof(d));
        int l,r; scanf("%d%d%d", &l,&r,&k);
        printf("%lld\n", solve(r)-solve(l-1));
    }

    return 0;
}




































