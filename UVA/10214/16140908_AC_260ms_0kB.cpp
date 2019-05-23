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
const int MAXN = 1e7+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 1e8+7;

int phi[MAXN], m, n;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }
void getphi(int n)
{
    phi[1] = 1;
    FOR(i,2,n) if (!phi[i]) {
        for (int j = i; j <= n; j += i) {
            if (!phi[j]) phi[j] = j;
            phi[j] = phi[j] / i * (i-1);
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    getphi(2005);
    while (scanf("%d%d", &m, &n), m) {
        LL cnt = 0;
        FOR(i,1,m) {
            cnt += n/i*phi[i];
            FOR(j,n/i*i+1,n) if (gcd(i,j) == 1) cnt++;
        }
        printf("%.7f\n", (4.0*cnt+4)/(4.0*m*n+2*m+2*n));
    }

    return 0;
}













































































