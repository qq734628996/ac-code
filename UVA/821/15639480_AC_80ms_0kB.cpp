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
const int MAXN = 1e2+5, MAXM = 5e2+5, INF = 0x3f3f3f3f, MOD = 998244353;

int g[MAXN][MAXN], x, y, kase;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d", &x, &y), x) {
        memset(g, 0x3f, sizeof(g));
        FOR(i,1,100) g[i][i] = 0;
        g[x][y] = 1;
        while (scanf("%d%d", &x, &y), x) g[x][y] = 1;
        FOR(k,1,100)FOR(i,1,100)FOR(j,1,100) g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
        double sum = 0;
        int cnt = 0;
        FOR(i,1,100)FOR(j,1,100) if (g[i][j] != INF && g[i][j]) sum += g[i][j], cnt++;
        printf("Case %d: average length between pages = %.3f clicks\n", ++kase, sum/cnt);
    }

    return 0;
}


















































































