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

int m,n,a[MAXN][MAXN],u[MAXN][MAXN],l[MAXN][MAXN],r[MAXN][MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &m,&n);
        REP(i,m)REP(j,n) {
            char s[2];
            scanf("%s", s);
            a[i][j]=s[0]=='F';
        }
        REP(i,m)REP(j,n) {
            u[i][j]=a[i][j];
            if (i && a[i][j]) u[i][j]+=u[i-1][j];
        }
        REP(i,m) {
            int L=-1;
            REP(j,n) {
                if (!a[i][j]) l[i][j]=0, L=j;
                else {
                    l[i][j]=L+1;
                    if (i && l[i][j]<l[i-1][j]) l[i][j]=l[i-1][j];
                }
            }
        }
        REP(i,m) {
            int R=n;
            PER(j,n) {
                if (!a[i][j]) r[i][j]=n, R=j;
                else {
                    r[i][j]=R-1;
                    if (i && r[i][j]>r[i-1][j]) r[i][j]=r[i-1][j];
                }
            }
        }
        int ans=0;
        REP(i,m)REP(j,n) {
            ans=max(ans,u[i][j]*(r[i][j]-l[i][j]+1));
        }
        printf("%d\n", ans*3);
    }

    return 0;
}










































