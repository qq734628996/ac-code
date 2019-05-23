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

int n, C[MAXN];
char op[10];
inline int lowbit(int x) { return x&-x; }
int sum(int x) { int ans = 0; while (0 < x) ans += C[x], x -= lowbit(x); return ans; }
void add(int x, int d) { while (x <= n) C[x] += d, x += lowbit(x); }

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    FOR(kase,1,T) {
        printf("Case %d:\n", kase);
        memset(C, 0, sizeof(C));
        scanf("%d", &n);
        FOR(i,1,n) {
            int x; scanf("%d", &x);
            add(i,x);
        }
        while (scanf("%s", op), op[0] != 'E') {
            int x, y; scanf("%d%d", &x, &y);
            if (op[0] == 'Q') printf("%d\n", sum(y) - sum(x-1));
            else if (op[0] == 'A') add(x, y);
            else add(x, -y);
        }
    }

    return 0;
}












































































