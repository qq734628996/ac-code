#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define TR(e,x) for(auto e = x.begin(); e != x.end(); e++)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n-1) printf("%d ", A[i]); printf("%d\n", A[n-1]); }
#define SHOW2(A,m,n) { REP(i,m) { REP(j,n-1) printf("%d ", A[i][j]); printf("%d\n", A[i][n-1]); } }
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)((x).size())
typedef long long LL;
const int MAXN  = 1e6, INF = ~0U>>1, MOD = ~0U>>1;










bool NO(false);

int read()
{
    int a[4];
    REP(i,4) scanf("%d", &a[i]);
    if (!a[0]) a[0] = read();
    if (!a[2]) a[2] = read();
    if (a[0]*a[1] != a[2]*a[3]) NO = true;
    return a[0]+a[2];
}



int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T;
    cin >> T;
    REP(i,T) {
        if (i) puts("");
        NO = false;
        read();
        puts(NO ? "NO" : "YES");
    }

































































    return 0;
}
