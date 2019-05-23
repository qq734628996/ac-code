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
const int MAXN = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n, m, d[MAXN], p[MAXN], vis[MAXN], kase;
struct node {
    int u, d, c;
    bool operator<(const node& o) const {
        if (d != o.d) return d > o.d;
        return c > o.c;
    }
};
vector<node> E[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d", &n, &m), n) {
        kase++;
        FOR(i,1,n) E[i].clear();
        REP(i,m) {
            int x, y, z, c; scanf("%d%d%d%d", &x, &y, &z, &c);
            E[x].pb((node){y,z,c}); E[y].pb((node){x,z,c});
        }
        memset(d+1, 0x3f, sizeof(int) * n);
        priority_queue<node> pq;
        pq.push((node){1,0,0}); d[1] = 0;
        while (!pq.empty()) {
            int u = pq.top().u; pq.pop();
            if (vis[u] == kase) continue;
            vis[u] = kase;
            REP(i,SZ(E[u])) {
                node& t = E[u][i];
                int v = t.u, dist = t.d, cost = t.c;
                if (d[v] > d[u]+dist || (d[v] == d[u]+dist && p[v] > cost)) {
                    d[v] = d[u]+dist;
                    p[v] = cost;
                    pq.push((node){v,d[v],p[v]});
                }
            }
        }
        int ans = 0;
        FOR(i,2,n) ans += p[i];
        printf("%d\n", ans);
    }

    return 0;
}

















































































