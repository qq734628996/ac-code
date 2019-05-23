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
const int MAXN = 1e3+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d", &n)) {
        vector<pii> V;
        REP(i,n) {
            int x, y; scanf("%d%d", &x, &y);
            V.pb(pii(y,x));
        }
        sort(ALL(V));
        multiset<int> S;
        REP(i,n) {
            int c = V[i].se, d = V[i].fi;
            if (SZ(S) < d) S.insert(c);
            else if (c > *S.begin()) {
                S.erase(S.begin());
                S.insert(c);
            }
        }
        int ans = 0;
        for (multiset<int>::iterator it = S.begin(); it != S.end(); it++) ans += *it;
        printf("%d\n", ans);
    }

    return 0;
}


















































































