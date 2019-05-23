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
const int MAXN = 5e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n, m, p[MAXN], r[MAXN];
int Find(int x)
{
    if (p[x] == x) return x;
    int root = Find(p[x]);
    r[x] = (r[x]+r[p[x]])%3;
    return p[x] = root;
}
bool Union(int op, int i, int j)
{
    int x = Find(i), y = Find(j);
    if (x == y) return r[i] == (op-1+r[j])%3;
    p[x] = y;
    r[x] = (-r[i]+op+2+r[j])%3;
    return true;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d%d", &n, &m);
    FOR(i,1,n) p[i] = i;
    int ans = 0;
    while (m--) {
        int op, x, y; scanf("%d%d%d", &op, &x, &y);
        if (x > n || y > n) ans++;
        else if (op == 2 && x == y) ans++;
        else if (!Union(op,x,y)) ans++;
    }
    printf("%d\n", ans);

    return 0;
}


















































































