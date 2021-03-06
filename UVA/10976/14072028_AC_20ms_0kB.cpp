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

int gcd(int m, int n) { return n? gcd(n, m%n) : m; }

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    int k, x, y;
    while (~scanf("%d", &k)) {
        int cnt = 0;
        FOR(i,k+1,k<<1)if(i-k == gcd(i-k, i*k)) cnt++;
        printf("%d\n", cnt);
        FOR(i,k+1,k<<1) {
            int g = gcd(i-k, i*k);
            if (i-k == g) {
                printf("1/%d = 1/%d + 1/%d\n", k, i*k/g, i);
            }
        }
    }

    return 0;
}

































