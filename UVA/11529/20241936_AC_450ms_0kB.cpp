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
const int INF = 0x3f3f3f3f, MOD = 1000000007;
const double PI = acos(-1), EPS = 1e-15;
const int MAXN = 2e3+9, MAXM = 1e4+5;

int dcmp(double x)
{
    if (fabs(x)<EPS) return 0;
    return x<0?-1:1;
}
struct point{ double x,y; };
struct Vector{ double x,y; };
Vector operator-(point& a, point& b){ return Vector{a.x-b.x,a.y-b.y}; }
double ang[MAXN<<1];
bool cmp(double a, double b){ return dcmp(a-b)<0; }
LL C(LL n, LL k)
{
    if (k==2) return n*(n-1)/2;
    if (k==3) return n*(n-1)*(n-2)/6;
    if (k==4) return n*(n-1)*(n-2)*(n-3)/24;
    return 0;
}
int n,kase;
point p[MAXN];
LL cal(int x)
{
    int m=0;
    REP(i,n) if (i!=x) {
        Vector v=p[i]-p[x];
        ang[m++]=atan2(v.y,v.x);
    }
    sort(ang,ang+m,cmp);
    int mm=m;
    REP(i,m) ang[mm++]=ang[i]+2*PI;
    LL res=0;
    int t=0;
    REP(i,m) {
        t=max(t,i+1);
        while (t<mm && dcmp(ang[t]-ang[i]-PI)<0) t++;
        res+=C(t-i-1,2);
    }
    return C(m,3)-res;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n)==1 && n) {
        REP(i,n) scanf("%lf%lf", &p[i].x,&p[i].y);
        LL ans=0;
        REP(i,n) ans+=cal(i);
        printf("City %d: %.2f\n", ++kase,(double)ans/C(n,3));
    }

    return 0;
}


































