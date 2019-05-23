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
const int MAXN = 5e3+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 1e9+7;

struct Fraction
{
    LL a, b; // a/b
    LL gcd(LL m, LL n) { return n ? gcd(n, m%n) : m; }
    LL lcm(LL m, LL n) { return m / gcd(m, n) * n; }
    Fraction (LL _a = 0, LL _b = 1) : a(_a), b(_b) {};
    Fraction& Set(LL m, LL n) { a = m; b = n; return *this; }
    Fraction& Simplify() {
        LL t = gcd(a, b); a /= t; b /= t;
        if (b < 0) b *= -1, a *= -1;
        return *this;
    }
    void print() { cout << a << '/' << b; }
    Fraction operator+ (const Fraction& o) {
        LL t = lcm(b, o.b);
        return Fraction( t / b * a + t / o.b * o.a, t );
    }
    Fraction operator* (const Fraction& o) {
        LL t1 = gcd(a, o.b), t2 = gcd(o.a, b);
        return Fraction( (a/t1)*(o.a/t2), (b/t2)*(o.b/t1) );
    }
    bool operator< (const Fraction& o) {
        LL t = lcm(b, o.b);
        return t / b * a < t / o.b * o.a;
    }
    bool operator<= (const Fraction& o) {
        LL t = lcm(b, o.b);
        return t / b * a <= t / o.b * o.a;
    }
    bool operator== (const Fraction& o) {
        LL t = lcm(b, o.b);
        return t / b * a == t / o.b * o.a;
    }
} B[30], S[30][30];

LL C[30][30];

void init_C(int n)
{
    FOR(i,0,n) {
        C[i][0] = 1;
        FOR(j,1,i) C[i][j] = C[i-1][j-1]+C[i-1][j];
    }
}

void init_B(int n)
{
    B[0] = Fraction(1);
    FOR(i,1,n) {
        B[i] = Fraction();
        REP(j,i) B[i] = B[i] + Fraction(C[i+1][j])*B[j];
        B[i] = B[i]*Fraction(-1,i+1);
        B[i].Simplify();
    }
}

void init_S(int n)
{
    FOR(k,0,n)FOR(i,0,k) {
        S[k][k+1-i] = Fraction(1,k+1)*Fraction(C[k+1][i])*Fraction(B[i]);
        if (i == 1) S[k][k+1-i].a *= -1;
        S[k][k+1-i].Simplify();
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int maxk = 20;
    init_C(maxk+1);
    init_B(maxk);
    init_S(maxk);

    int T; scanf("%d", &T);
    REP(kase,T) {
        int k; scanf("%d", &k);
        LL M = 1;
        FOR(i,0,k+1) M = Fraction().lcm(S[k][i].b,M);
        if (kase) puts("");
        printf("%lld", M);
        ROF(i,0,k+1) printf(" %lld", M/S[k][i].b*S[k][i].a);
        puts("");
    }

    return 0;
}












































































