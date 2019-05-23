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
const int MAXN = 1e3+5, INF = 0x3f3f3f3f, MOD = 998244353;

int T, n, m, d[MAXN], vis[MAXN], kase;
vector<pii> E[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        ++kase;
        scanf("%d%d", &n, &m);
        FOR(i,1,n) E[i].clear();
        FOR(i,1,m) {
            int x, y, z; scanf("%d%d%d", &x, &y, &z);
            E[x].pb(pii(y,z)); E[y].pb(pii(x,z));
        }
        memset(d+1, 0, sizeof(d));
        priority_queue<pii> pq;
        pq.push(pii(d[1] = INF, 1));
        while (!pq.empty()) {
            int u = pq.top().se; pq.pop();
            if (vis[u] == kase) continue;
            vis[u] = kase;
            REP(i,SZ(E[u])) {
                int v = E[u][i].fi, c = E[u][i].se;
                if (d[v] < min(d[u], c)) {
                    d[v] = min(d[u], c);
                    pq.push(pii(d[v], v));
                }
            }
        }
        printf("Scenario #%d:\n%d\n\n", kase, d[n]);
    }

    return 0;
}


















































































