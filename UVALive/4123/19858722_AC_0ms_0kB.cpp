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
const int MAXN = 1e3+5, MAXM = 5e3+5, INF = 0x3f3f3f3f, MOD = 1000000000;

LL d[MAXN][5][2],ans[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    REP(k,2) {
        d[1][0][k]=1;
        FOR(i,2,1000)REP(j,5) {
            d[i][j][k]=d[i-1][j][k];
            if (j>0) d[i][j][k]+=d[i-1][j-1][k];
        }
    }
    FOR(i,1,1000) {
        if (i<4 || i%2) continue;
        int x=(i+4)/2;
        ans[i]=d[x][3][0]+d[x][4][1]+d[x][4][0];
    }
    int n,kase=0;
    while (scanf("%d", &n)==1 && n) {
        printf("Case %d: %lld\n", ++kase,ans[n]);
    }

    return 0;
}




































