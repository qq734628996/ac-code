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

int n, m, vis[MAXN], ins[MAXN], kase;
double E[MAXN][MAXN], d[MAXN];
map<string, int> mp;

bool spfa_dfs(int u)
{
    vis[u] = ins[u] = kase;
    FOR(v,1,n) if (d[v] < d[u]*E[u][v]) {
        d[v] = d[u]*E[u][v];
        if (ins[v] == kase || spfa_dfs(v)) return true;
    }
    ins[u] = 0;
    return false;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n), n) {
        printf("Case %d: ", ++kase);
        mp.clear();
        FOR(i,1,n) {
            string s; cin >> s;
            mp[s] = i;
        }
        scanf("%d", &m);
        memset(E, 0, sizeof(E));
        FOR(i,1,m) {
            string s, t; double r; cin >> s >> r >> t;
            E[mp[s]][mp[t]] = r;
        }
        bool ok = false;
        FOR(i,1,n) if (vis[i] != kase) {
            FOR(i,1,n) d[i] = 0;
            d[i] = 1;
            ok |= spfa_dfs(i);
            if (ok) break;
        }
        puts(ok ? "Yes" : "No");
    }

    return 0;
}


















































































