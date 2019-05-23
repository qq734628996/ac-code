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

typedef long double ld;
ld logF[MAXN], p;
int n, kase;

ld logC(int n, int m) { return logF[n] - logF[m] - logF[n-m]; }

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    FOR(i,2,MAXN-1) logF[i] = logF[i-1] + log(i);
    while (~scanf("%d", &n)) {
        cin >> p;
        double ans = 0;
        FOR(i,0,n) {
            ld c = logC(2*n-i, n);
            ld x1 = c + (n+1)*log(p) + (n-i)*log(1-p);
            ld x2 = c + (n+1)*log(1-p) + (n-i)*log(p);
            ans += i*(exp(x1) + exp(x2));
        }
        printf("Case %d: %.6f\n", ++kase, ans);
    }

    return 0;
}













































































