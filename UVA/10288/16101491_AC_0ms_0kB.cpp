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
    Fraction operator- (const Fraction& o) {
        LL t = lcm(b, o.b);
        return Fraction( t / b * a - t / o.b * o.a, t );
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

    int digit(LL x) { int cnt = 0; while (x) cnt++, x /= 10; return cnt; }
    void print2() {
        if (a % b) {
            int c1 = digit(a / b) + 1, c2 = digit(b);
            REP(i,c1) putchar(' ');
            printf("%lld\n%lld ", a % b, a / b);
            REP(i,c2) putchar('-');
            puts("");
            REP(i,c1) putchar(' ');
            printf("%lld\n", b);
        } else printf("%lld\n", a / b);
    }
};



int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int n;
    while (~scanf("%d", &n)) {
        Fraction ans;
        FOR(i,1,n) ans = ans + Fraction(n,i), ans.Simplify();
        ans.print2();
    }

    return 0;
}













































































