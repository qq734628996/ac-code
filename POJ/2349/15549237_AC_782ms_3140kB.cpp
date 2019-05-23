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
const int MAXN = 1e3+5, MAXM = 1e6+5, INF = 0x3f3f3f3f, MOD = 998244353;

int T, n, m, num, x[MAXN], y[MAXN], u[MAXM], v[MAXM], r[MAXM], p[MAXN];
double w[MAXM];
inline double dist(int i, int j) { return hypot(x[i]-x[j], y[i]-y[j]); }
bool cmp(const int i, const int j) { return w[i] < w[j]; }
int Find(int x) { return p[x] == x ? x : p[x] = Find(p[x]); }
bool Union(int i, int j) { int x = Find(i), y = Find(j); if (x != y) p[x] = y; return x != y; }

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &num, &n);
        REP(i,n) scanf("%d%d", &x[i], &y[i]);
        if (num == n) { puts("0.00"); continue; }
        m = 0;
        REP(i,n)FOR(j,i+1,n-1) {
            u[m] = i, v[m] = j;
            w[m++] = dist(i,j);
        }
        REP(i,m) r[i] = i;
        sort(r, r+m, cmp);
        REP(i,n) p[i] = i;
        int cnt = 0;
        double ans = 0;
        REP(i,m) {
            int e = r[i];
            if (Union(u[e], v[e])) {
                ans = w[e];
                if (++cnt == n-num) break;
            }
        }
        printf("%.2f\n", ans);
    }

    return 0;
}


















































































