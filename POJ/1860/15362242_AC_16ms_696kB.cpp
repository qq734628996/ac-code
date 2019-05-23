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
const int MAXN = 1e2+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n, m, S, inq[MAXN];
double V, d[MAXN];
struct node {
    int u;
    double r, c;
};
vector<node> E[MAXN];

bool spfa()
{
    FOR(i,1,n) d[i] = 0;
    queue<int> Q;
    Q.push(S); d[S] = V;
    int cnt = 0;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        inq[u] = 0;
        REP(i,SZ(E[u])) {
            node& t = E[u][i];
            int v = t.u;
            double r = t.r, c = t.c;
            if (d[v] < (d[u]-c)*r) {
                d[v] = (d[u]-c)*r;
                if (!inq[v]) { inq[v] = 1; Q.push(v); if (++cnt > 2*(n+m)) return true; }
            }
        }
    }
    return false;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d%d%d%lf", &n, &m, &S, &V);
    FOR(i,1,m) {
        int x, y;
        double r1, c1, r2, c2;
        scanf("%d%d%lf%lf%lf%lf", &x, &y, &r1, &c1, &r2, &c2);
        E[x].pb((node){y,r1,c1}); E[y].pb((node){x,r2,c2});
    }
    puts(spfa() ? "YES" : "NO");

    return 0;
}


















































































