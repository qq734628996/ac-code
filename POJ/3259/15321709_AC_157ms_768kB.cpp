//#include "Head.h"
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
const int MAXN = 5e2+5, INF = 0x3f3f3f3f, MOD = 998244353;

int T, n, m, w, d[MAXN], inq[MAXN], cnt[MAXN], kase, vis[MAXN];
vector<pii> E[MAXN];

bool spfa(int s)
{
    memset(d+1, 0x3f, sizeof(int) * n);
    memset(cnt+1, 0, sizeof(int) * n);
    queue<int> Q;
    Q.push(s); inq[s] = kase; d[s] = 0; vis[s] = kase;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        inq[u] = 0;
        REP(i,SZ(E[u])) {
            int v = E[u][i].fi, dist = E[u][i].se;
            if (d[v] > d[u] + dist) {
                d[v] = d[u] + dist;
                if (inq[v] != kase) {
                    vis[v] = kase;
                    inq[v] = kase;
                    Q.push(v);
                    if (++cnt[v] > n) return false;
                }
            }
        }
    }
    return true;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    for (kase = 1; kase <= T; kase++) {
        scanf("%d%d%d", &n, &m, &w);
        FOR(i,1,n) E[i].clear();
        REP(i,m) {
            int x, y, z; scanf("%d%d%d", &x, &y, &z);
            E[x].pb(pii(y,z)); E[y].pb(pii(x,z));
        }
        REP(i,w) {
            int x, y, z; scanf("%d%d%d", &x, &y, &z);
            E[x].pb(pii(y,-z));
        }
        bool ans = true;
        FOR(i,1,n) if (vis[i] != kase) ans &= spfa(i);
        puts(ans ? "NO" : "YES");
    }

    return 0;
}


















































































