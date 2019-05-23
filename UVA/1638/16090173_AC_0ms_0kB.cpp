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
const int MAXN = 1e4+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 10056;

LL d[25][25][25];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    d[1][1][1] = 1;
    FOR(i,2,20)FOR(j,1,i)FOR(k,1,i) {
        if (j+k > i+1) d[i][j][k] = 0;
        else d[i][j][k] = d[i-1][j-1][k] + d[i-1][j][k-1] + d[i-1][j][k]*(i-2);
    }
    int T; scanf("%d", &T);
    while (T--) {
        int i, j, k; scanf("%d%d%d", &i, &j, &k);
        printf("%lld\n", d[i][j][k]);
    }

    return 0;
}













































































