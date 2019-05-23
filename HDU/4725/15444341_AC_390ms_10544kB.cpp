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
const int MAXN = 1e5+5, INF = 0x3f3f3f3f, MOD = 998244353;

int T, n, m, c, id[MAXN], d[MAXN*2], vis[MAXN*2], kase;
int to[MAXN*8], dis[MAXN*8], f[MAXN*2], nxt[MAXN*8], tot;
inline void add(int u, int v, int w)
{
    to[tot] = v;
    dis[tot] = w;
    nxt[tot] = f[u];
    f[u] = tot++;
}

void dij(int s)
{
    memset(d+1, 0x3f, sizeof(int) * 2*n);
    priority_queue<pii> pq;
    pq.push(pii(d[s] = 0, s));
    while (!pq.empty()) {
        int u = pq.top().se; pq.pop();
        if (vis[u] == kase) continue;
        vis[u] = kase;
        for (int i = f[u]; ~i; i = nxt[i]) {
            int v = to[i], dist = dis[i];
            if (d[v] > d[u] + dist) {
                d[v] = d[u] + dist;
                pq.push(pii(-d[v], v));
            }
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    for (kase = 1; kase <= T; kase++) {
        printf("Case #%d: ", kase);
        scanf("%d%d%d", &n, &m, &c);
        memset(f+1, -1, sizeof(int) * 2*n); tot = 0;
        FOR(i,1,n) scanf("%d", &id[i]);
        FOR(i,1,n) vis[id[i]] = -kase;
        FOR(i,1,n) {
            add(id[i]+n,i,0);
            if (vis[id[i]-1] == -kase) add(i,id[i]-1+n,c);
            if (vis[id[i]+1] == -kase) add(i,id[i]+1+n,c);
        }
        FOR(i,1,m) {
            int x, y, z; scanf("%d%d%d", &x, &y, &z);
            add(x,y,z);
            add(y,x,z);
        }
        dij(1);
        if (d[n] == INF) puts("-1");
        else printf("%d\n", d[n]);
    }

    return 0;
}


















































































