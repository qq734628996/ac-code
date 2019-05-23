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
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define TR(e,x) for(auto e = x.begin(); e != x.end(); e++)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n-1) printf("%d ", A[i]); printf("%d\n", A[n-1]); }
#define SHOW2(A,m,n) { REP(i,m) { REP(j,n-1) printf("%d ", A[i][j]); printf("%d\n", A[i][n-1]); } }
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)((x).size())
typedef long long LL;
typedef pair<int, int> pii;
const int MAXN  = 505, INF = 0x3f3f3f3f, MOD = ~0U>>1;

int T, n, m, w, a[MAXN][MAXN];

bool jdg()
{
    FOR(k,1,n)FOR(i,1,n) {
        FOR(j,1,n) if (a[i][k]+a[k][j] < a[i][j]) a[i][j] = a[i][k]+a[k][j];
        if (a[i][i] < 0) return true;
    }
    return false;
}

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &w);
        memset(a, 0x3f, sizeof(a));
        FOR(i,1,n) a[i][i] = 0;
        REP(i,m) {
            int x, y, d; scanf("%d%d%d", &x, &y, &d);
            a[x][y] = a[y][x] = min(a[x][y], d);
        }
        REP(i,w) {
            int x, y, d; scanf("%d%d%d", &x, &y, &d);
            a[x][y] = min(a[x][y], -d);
        }
        puts(jdg() ? "YES" : "NO");
    }

    return 0;
}

















































































