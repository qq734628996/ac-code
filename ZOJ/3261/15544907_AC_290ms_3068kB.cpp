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

int n, m, q, a[MAXN], r[MAXN], id[MAXN], p[MAXN], u[MAXN], v[MAXN], ans[MAXN], kase;
char s[MAXN][10];
bool cmp(const int i, const int j)
{
    if (a[i] != a[j]) return a[i] < a[j];
    return i > j;
}
int Find(int x) { return p[x] == x ? x : p[x] = Find(p[x]); }
void Union(int i, int j)
{
    int x = Find(i), y = Find(j);
    if (x != y) {
        if (id[x] < id[y]) p[x] = y;
        else p[y] = x;
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d", &n)) {
        if (kase++) puts("");
        REP(i,n) scanf("%d", &a[i]);
        scanf("%d", &m);
        set<pii> S;
        REP(i,m) {
            int x, y; scanf("%d%d", &x, &y);
            S.insert(pii(min(x,y), max(x,y)));
        }
        scanf("%d", &q);
        REP(i,q) {
            scanf("%s%d", s[i], &u[i]);
            if (s[i][0] == 'd') {
                scanf("%d", &v[i]);
                S.erase(pii(min(u[i],v[i]), max(u[i],v[i])));
            }
        }
        REP(i,n) r[i] = i;
        sort(r, r+n, cmp);
        REP(i,n) id[r[i]] = i;
        REP(i,n) p[i] = i;
        for (set<pii>::iterator it = S.begin(); it != S.end(); it++)
            Union(it->fi, it->se);
        PER(i,q) {
            if (s[i][0] == 'd') Union(u[i], v[i]);
            else {
                int x = Find(u[i]);
                ans[i] = a[x] > a[u[i]] ? x : -1;
            }
        }
        REP(i,q) if (s[i][0] == 'q') printf("%d\n", ans[i]);
    }

    return 0;
}


















































































