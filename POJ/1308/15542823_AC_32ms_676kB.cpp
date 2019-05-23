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

int n, m, u[MAXN], v[MAXN], p[MAXN], kase;
int Find(int x) { return p[x] == x ? x : p[x] = Find(p[x]); }
bool Union(int i,int j) { int x = Find(i), y = Find(j); if (x != y) p[y] = x; return x != y; }

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d", &u[0], &v[0]), u[0] != -1) {
        if (!u[0]) { printf("Case %d is a tree.\n", ++kase); continue; }
        n = max(u[0], v[0]); m = 1;
        while (scanf("%d%d", &u[m], &v[m]), u[m]) n = max(n, max(u[m],v[m])), m++;
        set<int> S;
        REP(i,m) S.insert(u[i]), S.insert(v[i]);
        for (set<int>::iterator it = S.begin(); it != S.end(); it++) p[*it] = *it;
        bool flag = true;
        REP(i,m) {
            if (!Union(u[i],v[i])) { flag = false; break; }
        }
        int root = Find(*S.begin());
        for (set<int>::iterator it = S.begin(); it != S.end(); it++) {
            if (Find(*it) != root) { flag = false; break; }
        }
        printf("Case %d is%sa tree.\n", ++kase, flag ? " " : " not ");
    }

    return 0;
}


















































































