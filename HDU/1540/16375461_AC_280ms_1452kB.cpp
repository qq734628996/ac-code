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
const int MAXN = 5e4+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 1000000007;



int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        char op[10];
        set<int> S;
        stack<int> stk;
        while (m--) {
            scanf("%s", op);
            if (op[0] == 'R') {
                if (!stk.empty()) {
                    int x = stk.top(); stk.pop();
                    S.erase(x);
                }
            } else {
                int x; scanf("%d", &x);
                if (op[0] == 'D') S.insert(x), stk.push(x);
                else {
                    set<int>::iterator L = lower_bound(ALL(S),x);
                    set<int>::iterator R = upper_bound(ALL(S),x);
                    if (L == R) {
                        int l = 1, r = n;
                        if (L != S.begin()) l = *--L+1;
                        if (R != S.end()) r = *R-1;
                        printf("%d\n", r-l+1);
                    } else puts("0");
                }
            }
        }
    }

    return 0;
}












































































