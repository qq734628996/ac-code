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
const int MAXN = 2e3+5, MAXM = 2e6+5, INF = 0x3f3f3f3f, MOD = 998244353;

int T, n, m, u[MAXM], v[MAXM], w[MAXM], r[MAXM], p[MAXN];
bool cmp(const int i, const int j) { return w[i] < w[j]; }
int Find(int x) { return p[x] == x ? x : p[x] = Find(p[x]); }
bool Union(int i, int j) { int x = Find(i), y = Find(j); if (x != y) p[x] = y; return x != y; }
char s[MAXN][10];
inline int cnt(int i, int j)
{
    int ans = 0;
    REP(k,7) if (s[i][k] != s[j][k]) ans++;
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n), n) {
        REP(i,n) scanf("%s", s[i]);
        m = 0;
        REP(i,n)FOR(j,i+1,n-1) {
            u[m] = i, v[m] = j;
            w[m++] = cnt(i,j);
        }
        REP(i,m) r[i] = i;
        sort(r, r+m, cmp);
        REP(i,n) p[i] = i;
        int ans = 0;
        REP(i,m) {
            int e = r[i];
            if (Union(u[e], v[e])) ans += w[e];
        }
        printf("The highest possible quality is 1/%d.\n", ans);
    }

    return 0;
}


















































































