#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define TR(e,x) for(auto e = x.begin(); e != x.end(); e++)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n-1) printf("%d ", A[i]); printf("%d\n", A[n-1]); }
#define SHOW2(A,m,n) { REP(i,m) { REP(j,n-1) printf("%d ", A[i][j]); printf("%d\n", A[i][n-1]); } }
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)((x).size())
typedef long long LL;
const int MAXN  = 1e2+5, INF = ~0U>>1;

int n, a[MAXN];
inline bool vld(int a, int b, int c)
{
    return a+b>c && a+c>b && b+c>a;
}
double calc(int a, int b, int c)
{
    double s = (a+b+c)/2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main()
{

    while (scanf("%d", &n), n) {
        REP(i,n) scanf("%d", &a[i]);
        sort(a, a+n, greater<int>());
        double res = 0.0;
        for (int i = 0; i + 2 < n; ) {
            if (vld(a[i], a[i+1], a[i+2])) {
                res += calc(a[i], a[i+1], a[i+2]);
                i += 3;
            }else i++;
        }
        printf("%.2f\n", res);
    }

    return 0;
}









































