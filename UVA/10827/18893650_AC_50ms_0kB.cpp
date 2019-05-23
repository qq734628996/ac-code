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

int n,a[MAXN][MAXN],S[MAXN][MAXN],id[MAXN],q[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        FOR(i,1,n)FOR(j,1,n) {
            scanf("%d", &a[i][j]);
            a[i+n][j]=a[i][j+n]=a[i+n][j+n]=a[i][j];
        }
        FOR(i,1,2*n)FOR(j,1,2*n) {
            S[i][j]=S[i-1][j]+S[i][j-1]-S[i-1][j-1]+a[i][j];
        }
        int ans=-INF;
        FOR(l,1,n)FOR(r,l,l+n-1) {
            int ma=-INF, st=0, ed=1;
            id[0]=q[0]=0;
            FOR(j,1,2*n) {
                if (j-id[st]>n) st++;
                int now=S[r][j]-S[l-1][j];
                ma=max(ma, now-q[st]);
                while (st<ed && q[ed-1]>=now) ed--;
                id[ed]=j;
                q[ed++]=now;
            }
            ans=max(ans,ma);
        }
        printf("%d\n", ans);
    }

    return 0;
}









































