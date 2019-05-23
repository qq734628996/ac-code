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

int n, m, u[MAXM], v[MAXM], w[MAXM], r[MAXM], p[MAXN];
bool cmp(const int i, const int j) { return w[i] < w[j]; }
int Find(int x) { return p[x] == x ? x : p[x] = Find(p[x]); }
bool Union(int i, int j) { int x = Find(i), y = Find(j); if (x != y) p[x] = y; return x != y; }

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &n);
    m = 0;
    FOR(i,1,n)FOR(j,1,n) {
        scanf("%d", &w[m]);
        if (j > i) {
            u[m] = i; v[m] = j;
            m++;
        }
    }
    REP(i,m) r[i] = i;
    sort(r, r+m, cmp);
    vector<int> Kruskal;
    FOR(i,1,n) p[i] = i;
    REP(i,m) {
        int e = r[i];
        if (Union(u[e], v[e])) Kruskal.pb(e);
    }
    FOR(i,1,n) p[i] = i;
    int q; scanf("%d", &q);
    REP(i,q) {
        int x, y; scanf("%d%d", &x, &y);
        Union(x, y);
    }
    int ans = 0;
    REP(i,SZ(Kruskal)) {
        int e = Kruskal[i];
        if (Union(u[e], v[e])) ans += w[e];
    }
    printf("%d\n", ans);

    return 0;
}


















































































