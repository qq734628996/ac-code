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

int m,n,num[12][12],kase;
char a[12][12];
#define vld(i,j) (0<=i&&i<m&&0<=j&&j<n&&a[i][j]!='*')

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d", &m,&n)==2 && m) {
        if (kase++) puts("");
        printf("puzzle #%d:\n", kase);
        REP(i,m) scanf("%s", a[i]);
        memset(num,0,sizeof(num));
        int cnt=0;
        REP(i,m)REP(j,n) if (vld(i,j) && (!vld(i-1,j) || !vld(i,j-1))) num[i][j]=++cnt;
        puts("Across");
        REP(i,m)REP(j,n) if (vld(i,j) && !vld(i,j-1)) {
            printf("%3d.", num[i][j]);
            while (vld(i,j)) putchar(a[i][j++]);
            puts("");
        }
        puts("Down");
        REP(i,m)REP(j,n) if (vld(i,j) && !vld(i-1,j)) {
            printf("%3d.", num[i][j]);
            int ii=i;
            while (vld(ii,j)) putchar(a[ii++][j]);
            puts("");
        }
    }

    return 0;
}














































