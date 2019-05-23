

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
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define TR(e,x) for(auto e = x.begin(); e != x.end(); e++)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n-1) printf("%d ", A[i]); printf("%d\n", A[n-1]); }
#define SHOW2(A,m,n) { REP(i,m) { REP(j,n-1) printf("%d ", A[i][j]); printf("%d\n", A[i][n-1]); } }
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)((x).size())
typedef long long LL;
const int MAXN  = 1e4, INF = ~0U>>1, MOD = ~0U>>1;








typedef pair<int, int> pint;

int main()
{
    #ifdef LOCAL
        freopen("i", "r", stdin);
        freopen("o", "w", stdout);
    #endif //LOCAL

    int T, n, a, b;
    scanf("%d", &T);
    while (T--) {
        set<pint> s;
        int mi = INF, ma = -INF;
        scanf("%d", &n);
        REP(i,n) {
            scanf("%d%d", &a, &b);
            mi = min(mi, a);
            ma = max(ma, a);
            s.insert(pint(a, b));
        }
        bool Y(true);
        for (auto& i : s) {
            if (!s.count(pint(mi+ma-i.first, i.second))) {
                Y = false;
                break;
            }
        }
        puts(Y ? "YES" : "NO");
    }

































    return 0;
}





