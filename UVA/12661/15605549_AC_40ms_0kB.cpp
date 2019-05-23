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
const int MAXN = 3e2+5, MAXM = 1e6+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n, m, s, t, d[MAXN], kase;
struct edge {
    int to, a, b, t;
};
vector<edge> E[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d%d%d%d", &n, &m, &s, &t)) {
        FOR(i,1,n) E[i].clear();
        REP(i,m) {
            int from, to, a, b, t; scanf("%d%d%d%d%d", &from, &to, &a, &b, &t);
            if (t <= a) E[from].pb((edge){to, a, b, t});
        }
        priority_queue<pii> pq;
        memset(d, 0x3f, sizeof(d));
        pq.push(pii(d[s] = 0, s));
        while (!pq.empty()) {
            int u = pq.top().se; pq.pop();
            REP(i,SZ(E[u])) {
                edge& e = E[u][i];
                int time = d[u]%(e.a+e.b);
                if (time + e.t <= e.a) {
                    if (d[e.to] > d[u] + e.t) {
                        d[e.to] = d[u] + e.t;
                        pq.push(pii(-d[e.to], e.to));
                    }
                } else {
                    time = e.a+e.b-time;
                    if (d[e.to] > d[u] + e.t + time) {
                        d[e.to] = d[u] + e.t + time;
                        pq.push(pii(-d[e.to], e.to));
                    }
                }
            }
        }
        printf("Case %d: %d\n", ++kase, d[t]);
    }

    return 0;
}


















































































