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
const int MAXN = 4e5+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 10056;



int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int n;
    double t, d[35];
    while (scanf("%d%lf", &n, &t), n) {
        d[n] = 1<<n;
        ROF(i,0,n-1) {
            double p0 = max(t, (1<<i)/d[i+1]);
            double p1 = (p0-t)/(1-t);
            d[i] = (1<<i)*p1 + (p0+1)/2*d[i+1]*(1-p1);
        }
        printf("%.3f\n", d[0]);
    }

    return 0;
}













































































