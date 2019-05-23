#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>

#include <iostream>
#include <algorithm>
//#include <unordered_map>
//#include <unordered_set>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
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
const int MAXN = 1e4+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n, m, u[MAXM], v[MAXM], r[MAXM], p[MAXM];
double x[MAXN], y[MAXN], z[MAXN], R[MAXN], w[MAXM];
inline double dis(double x, double y, double z)
{ return sqrt(x*x + y*y + z*z); }
inline double dist(int i, int j)
{ return dis(x[i]-x[j], y[i]-y[j], z[i]-z[j]); }
bool cmp(const int i, const int j) { return w[i] < w[j]; }
int Find(int x) { return p[x] == x ? x : p[x] = Find(p[x]); }
bool Union(int i, int j) { int x = Find(i), y = Find(j); if (x != y) p[x] = y; return x != y; }

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n), n) {
        REP(i,n) scanf("%lf%lf%lf%lf", &x[i],&y[i],&z[i],&R[i]);
        m = 0;
        REP(i,n)REP(j,n) {
            u[m] = i; v[m] = j;
            w[m] = max(0.0,dist(i,j)-R[i]-R[j]);
            m++;
        }
        REP(i,m) r[i] = i;
        sort(r, r+m, cmp);
        REP(i,n) p[i] = i;
        double ans = 0;
        REP(i,m) {
            int e = r[i];
            if (Union(u[e], v[e])) ans += w[e];
        }
        printf("%.3f\n", ans);
    }

    return 0;
}


















































































