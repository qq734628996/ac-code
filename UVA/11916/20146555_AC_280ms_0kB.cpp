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
const int MAXN = 1e6+9, MAXM = 2e6+5, INF = 0x3f3f3f3f, MOD = 100000007;

void ex_gcd(LL a, LL b, LL& d, LL& x, LL& y)
{
    if (!b) d=a, x=1, y=0;
    else ex_gcd(b,a%b,d,y,x), y-=x*(a/b);
}
LL powMod(LL x, LL e)
{
    if (!e) return 1;
    return e&1 ? powMod(x,e-1)*x%MOD : powMod(x*x%MOD,e>>1);
}
LL inv(LL a) { return powMod(a,MOD-2); }
int log_mod(int a, int b)
{
    int m=sqrt(MOD+0.5);
    int v=inv(powMod(a,m));
    map<int,int> x;
    x[1]=0;
    for (int i=1, e=1; i<m; i++) {
        e=(LL)e*a%MOD;
        if (!x.count(e)) x[e]=i;
    }
    REP(i,m) {
        if (x.count(b)) return i*m+x[b];
        b=(LL)b*v%MOD;
    }
    return -1;
}
const int maxb=500+10;
int n,m,k,b,r,x[maxb],y[maxb];
set<pii> bset;
int count()
{
    int c=0;
    REP(i,b) {
        if (x[i]!=m && !bset.count({x[i]+1,y[i]})) c++;
    }
    c+=n;
    REP(i,b) c-=(x[i]==1);
    return powMod(k,c)*powMod(k-1,(LL)m*n-b-c)%MOD;
}
int doit()
{
    int cnt=count();
    if (cnt==r) return m;
    int c=0;
    REP(i,b) c+=(x[i]==m);
    m++;
    cnt=cnt*powMod(k,c)%MOD;
    cnt=cnt*powMod(k-1,n-c)%MOD;
    if (cnt==r) return m;
    return log_mod(powMod(k-1,n), r*inv(cnt)%MOD)+m;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    FOR(kase,1,T) {
        scanf("%d%d%d%d", &n,&k,&b,&r);
        bset.clear();
        m=1;
        REP(i,b) {
            scanf("%d%d", &x[i],&y[i]);
            m=max(m,x[i]);
            bset.insert({x[i],y[i]});
        }
        printf("Case %d: %d\n", kase,doit());
    }

    return 0;
}




































