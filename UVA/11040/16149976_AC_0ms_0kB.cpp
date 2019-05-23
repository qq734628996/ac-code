#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
#define TR(e,x) for(auto e = x.begin(); e != x.end(); e++)
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
const int MAXN = 1e4+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 1e8+7;

int a[100][100];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        FOR(i,1,9)if(i&1)FOR(j,1,i)if(j&1) scanf("%d", &a[i][j]);
        FOR(i,1,9)if(i&1)FOR(j,1,i)if(!(j&1))
            a[i][j] = (a[i-2][j-1]-a[i][j-1]-a[i][j+1])/2;
        FOR(i,1,9)if(!(i&1))FOR(j,1,i) a[i][j] = a[i+1][j]+a[i+1][j+1];
        FOR(i,1,9) {
            printf("%d", a[i][1]);
            FOR(j,2,i) printf(" %d", a[i][j]);
            puts("");
        }
    }

    return 0;
}













































































