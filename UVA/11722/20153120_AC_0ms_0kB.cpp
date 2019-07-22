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
const int MAXN = 1e3+9, MAXM = 1e4+5;

double t1, t2, s1, s2, width, height;
int kase;
double get_area(double w)
{
    double ly=t1+w, ry=t2+w;
    double tx=s2-w, bx=s1-w;
    bool on_left = s1<=ly && ly<=s2;
    bool on_right = s1<=ry && ry<=s2;
    bool on_top = t1<=tx && tx<=t2;
    bool on_bottom = t1<=bx && bx<=t2;
    if(on_left && on_right) return (s2-ly+s2-ry)*width*0.5;
    if(on_left && on_top) return (s2-ly)*(tx-t1)*0.5;
    if(on_top && on_bottom) return (bx-t1+tx-t1)*height*0.5;
    if(on_right && on_bottom) return height*width-(t2-bx)*(ry-s1)*0.5;
    return ly<=s1 ? width*height:0;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        double w;
        scanf("%lf%lf%lf%lf%lf", &t1,&t2,&s1,&s2,&w);
        width=t2-t1;
        height=s2-s1;
        double a1=get_area(w);
        double a2=get_area(-w);
        printf("Case #%d: %.6f\n", ++kase, (a2-a1)/width/height);
    }

    return 0;
}




































