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
const int MAXN = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int T, n, m, p[MAXN], r[MAXN];
int Find(int x)
{
    if (p[x] == x) return x;
    int root = Find(p[x]);
    r[x] ^= r[p[x]];
    return p[x] = root;
}
bool Union(int i, int j)
{
    int x = Find(i), y = Find(j);
    if (x == y) return r[i]^1 == r[j];
    p[x] = y;
    r[x] = r[i]^r[j]^1;
    return true;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    FOR(kase,1,T) {
        scanf("%d%d", &n, &m);
        FOR(i,1,n) p[i] = i, r[i] = 0;
        bool flag = true;
        FOR(i,1,m) {
            int x, y; scanf("%d%d", &x, &y);
            flag &= Union(x, y);
        }
        printf("Scenario #%d:\n", kase);
        if (flag) puts("No suspicious bugs found!\n");
        else puts("Suspicious bugs found!\n");
    }

    return 0;
}


















































































