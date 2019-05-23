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
const int MAXN = 1e3+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n,m,y[MAXN],on[MAXN],on2[MAXN],l[MAXN],kase;
pii a[123];
int solve()
{
    REP(i,n) y[i]=a[i].se;
    sort(a,a+n);
    sort(y,y+n);
    m=unique(y,y+n)-y;
    if (m<=2) return n;
    int ans=0;
    REP(r1,m)FOR(r2,r1+1,m-1) {
        int k=0;
        REP(i,n) {
            if (!i || a[i].fi!=a[i-1].fi) {
                k++;
                on[k]=on2[k]=0;
                l[k]=l[k-1]+on2[k-1]-on[k-1];
            }
            if (y[r1]< a[i].se && a[i].se< y[r2]) on[k]++;
            if (y[r1]<=a[i].se && a[i].se<=y[r2]) on2[k]++;
        }
        if (k<=2) return n;
        int M=0;
        FOR(j,1,k) {
            ans=max(ans,l[j]+on2[j]+M);
            M=max(M,on[j]-l[j]);
        }
    }
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n)==1 && n) {
        REP(i,n) scanf("%d%d", &a[i].fi,&a[i].se);
        printf("Case %d: %d\n", ++kase,solve());
    }

    return 0;
}










































