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
const int INF = 0x3f3f3f3f, MOD = 100000007;
const int MAXN = 1e2+9, MAXM = 1e4+5;

int gcd(int a, int b) { return b==0 ? a : gcd(b,a%b); }

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int n,t;
    while (scanf("%d%d", &n,&t)==2 && n) {
        LL pow[MAXN];
        pow[0]=1;
        FOR(i,1,n) pow[i]=pow[i-1]*t;
        LL a=0;
        REP(i,n) a+=pow[gcd(i,n)];
        LL b=0;
        if (n&1) b=n*pow[(n+1)/2];
        else b=n/2*(pow[n/2+1]+pow[n/2]);
        printf("%lld %lld\n", a/n, (a+b)/2/n);
    }

    return 0;
}




































