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
const int MAXN  = 1e3+5, INF = ~0U>>1, MOD = ~0U>>1;



int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    int n, kase = 0;
    while (scanf("%d", &n), n) {
        if (kase++) puts("");
        int ed = 98765/n + 1, ok = 0;
        FOR(i,1234,ed) {
            int _j = i * n, _i = i, vis[10] = {0};
            if (_i < 1e4) vis[0] = 1;
            for ( ; _j; _j/=10) vis[_j%10] = 1;
            for ( ; _i; _i/=10) vis[_i%10] = 1;
            bool flag = true;
            REP(i,10)if(!vis[i])flag = false;
            if (flag) {
                printf("%d / %s%d = %d\n", i*n, i<1e4 ? "0" : "", i, n);
                ok = 1;
            }
        }
        if (!ok) printf("There are no solutions for %d.\n", n);
    }

    return 0;
}

































