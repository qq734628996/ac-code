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
const int MAXN = 2e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n, m, u[MAXN], v[MAXN], w[MAXN], p[MAXN], r[MAXN];
char s[10];
set<int> S;
map<int, int> mp;
int Find(int x)
{
    if (p[x] == x) return x;
    int root = Find(p[x]);
    r[x] ^= r[p[x]];
    return p[x] = root;
}
bool Union(int i, int j, int op)
{
    int x = Find(i), y = Find(j);
    if (x == y) return r[i]^op == r[j];
    p[max(x,y)] = min(x,y);
    r[max(x,y)] = r[i]^op^r[j];
    return true;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d%d", &n, &m);
    REP(i,m) scanf("%d%d%s", &u[i], &v[i], s), w[i] = s[0]=='o';
    REP(i,m) S.insert(u[i]), S.insert(v[i]+1);
    int tot = 0;
    for (set<int>::iterator it = S.begin(); it != S.end(); it++) mp[*it] = tot++;
    REP(i,tot) p[i] = i, r[i] = 0;
    int i = 0;
    for (; i < m; i++) if (!Union(mp[u[i]], mp[v[i]+1], w[i])) break;
    printf("%d\n", i);

    return 0;
}


















































































