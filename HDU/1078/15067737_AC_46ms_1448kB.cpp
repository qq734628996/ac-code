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
const int MAXN = 1e2+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n, k, a[MAXN][MAXN], d[MAXN][MAXN];

int dp(int u, int v)
{
    int& ans = d[u][v];
    if (ans != -1) return ans;
    ans = 0;
    FOR(i,max(0,u-k),min(n-1,u+k))if(a[u][v] < a[i][v]) ans = max(ans, dp(i, v));
    FOR(j,max(0,v-k),min(n-1,v+k))if(a[u][v] < a[u][j]) ans = max(ans, dp(u, j));
    return ans += a[u][v];
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d", &n, &k), n != -1) {
        REP(i,n)REP(j,n) scanf("%d", &a[i][j]);
        memset(d, -1, sizeof(d));
        printf("%d\n", dp(0, 0));
    }

    return 0;
}




















































































