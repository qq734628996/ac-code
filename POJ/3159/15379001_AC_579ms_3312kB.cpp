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
const int MAXN = 3e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

const int MAXM = 2e5;
int n, m, d[MAXN], vis[MAXN], from[MAXM], to[MAXM], w[MAXM], f[MAXN], nxt[MAXM];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d%d", &n, &m);
    memset(f+1, -1, sizeof(int) * n);
    FOR(i,1,m) {
        scanf("%d%d%d", &from[i], &to[i], &w[i]);
        nxt[i] = f[from[i]]; f[from[i]] = i;
    }
    memset(d+1, 0x3f, sizeof(int) * n);
    priority_queue<pii> pq;
    pq.push(pii(d[1] = 0, 1));
    while (!pq.empty()) {
        int u = pq.top().se; pq.pop();
        if (vis[u] == 1) continue;
        vis[u] = 1;
        for (int j = f[u]; ~j; j = nxt[j]) {
            int v = to[j], dist = w[j];
            if (d[v] > d[u] + dist) {
                d[v] = d[u] + dist;
                pq.push(pii(-d[v], v));
            }
        }
    }
    printf("%d\n", d[n]);

    return 0;
}


















































































