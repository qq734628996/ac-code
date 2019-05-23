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
const int MAXN = 1e6+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 1e9+7;



int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    double g = 9.81, k, l, s, w, v;
    while (scanf("%lf%lf%lf%lf", &k, &l, &s, &w), k+l+s+w != 0.0) {
        if (s <= l) v = 2*g*s;
        else v = 2*g*s - k*(s-l)*(s-l)/w;
        if (v < 0) puts("Stuck in the air.");
        else if (v > 100) puts("Killed by the impact.");
        else puts("James Bond survives.");
    }

    return 0;
}













































































