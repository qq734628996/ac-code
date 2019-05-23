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
const int MAXN = 2e2+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n, x[MAXN], y[MAXN], kase;
double d[MAXN][MAXN];
inline double dis(int i, int j) { return hypot(x[i]-x[j], y[i]-y[j]); }

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n), n) {
        FOR(i,1,n) scanf("%d%d", &x[i], &y[i]);
        FOR(i,1,n)FOR(j,1,n) d[i][j] = dis(i, j);
        FOR(k,1,n)FOR(i,1,n)FOR(j,1,n) d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
        printf("Scenario #%d\nFrog Distance = %.3f\n\n", ++kase, d[1][2]);
    }

    return 0;
}


















































































