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
const int MAXN  = 1e3+5, INF = 0x3f3f3f3f, MOD = ~0U>>1;

int n, m, x, d[2][MAXN], ans;
vector<pii> E[2][MAXN];

void Dijkstra(int u)
{
    priority_queue<pii> pq;
    d[u][x] = 0;
    pq.push(pii(-d[u][x], x));
    while (!pq.empty()) {
        int now = pq.top().second; pq.pop();
        REP(i,SZ(E[u][now])) {
            int v = E[u][now][i].first;
            int t = E[u][now][i].second;
            if (d[u][now]+t < d[u][v]) {
                d[u][v] = d[u][now]+t;
                pq.push(pii(-d[u][v], v));
            }
        }
    }
}

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d%d%d", &n, &m, &x);
    while (m--) {
        int i, j, t; scanf("%d%d%d", &i, &j, &t);
        E[0][i].push_back(pii(j, t));
        E[1][j].push_back(pii(i, t));
    }
    memset(d, 0x3f, sizeof(d));
    REP(i,2) Dijkstra(i);
    FOR(i,1,n) ans = max(ans, d[0][i]+d[1][i]);
    printf("%d\n", ans);

    return 0;
}

















































































