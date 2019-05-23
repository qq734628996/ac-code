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
const int MAXN = 1e3+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n, d, x[MAXN], y[MAXN], p[MAXN];
char op[10];
int Find(int x) { return p[x] == x ? x : p[x] = Find(p[x]); }
void Union(int i, int j) { int xx = Find(i), yy = Find(j); if (xx != yy) p[xx] = yy; }
set<int> S;
inline double dist(int i, int j) { return hypot(x[i]-x[j], y[i]-y[j]); }

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d%d", &n, &d);
    FOR(i,1,n) scanf("%d%d", &x[i], &y[i]);
    FOR(i,1,n) p[i] = i;
    while (~scanf("%s", op)) {
        if (op[0] == 'O') {
            int u; scanf("%d", &u);
            for (set<int>::iterator it = S.begin(); it != S.end(); it++) {
                int v = *it;
                if (dist(u, v) < d+1e-9) Union(u, v);
            }
            S.insert(u);
        } else {
            int u, v; scanf("%d%d", &u, &v);
            int xx = Find(u), yy = Find(v);
            puts(xx == yy ? "SUCCESS" : "FAIL");
        }
    }

    return 0;
}


















































































