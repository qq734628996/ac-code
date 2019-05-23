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
const int MAXN = 1e6+5, INF = 0x3f3f3f3f, MOD = 998244353;

int T, n, m, node[2][MAXN], w[MAXN], f[2][MAXN], nxt[2][MAXN], d[MAXN], inq[MAXN], kase;
LL spfa(int i)
{
    int sign = (i ? 1 : -1) * kase;
    memset(d+1, 0x3f, sizeof(int) * n);
    queue<int> Q;
    Q.push(1); d[1] = 0;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        inq[u] = 0;
        for (int j = f[i][u]; ~j; j = nxt[i][j]) {
            int v = node[1-i][j], dist = w[j];
            if (d[v] > d[u] + dist) {
                d[v] = d[u] + dist;
                if (inq[v] != sign) {
                    inq[v] = sign;
                    Q.push(v);
                }
            }
        }
    }
    LL ans = 0;
    FOR(j,1,n) ans += d[j];
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    for (kase = 1; kase <= T; kase++) {
        scanf("%d%d", &n, &m);
        REP(i,2) memset(f[i]+1, -1, sizeof(int) * n);
        FOR(i,1,m) {
            scanf("%d%d%d", &node[0][i], &node[1][i], &w[i]);
            REP(k,2) { nxt[k][i] = f[k][node[k][i]]; f[k][node[k][i]] = i; }
        }
        printf("%lld\n", spfa(0)+spfa(1));
    }

    return 0;
}


















































































