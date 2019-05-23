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
const int MAXN = 2e5+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n, m, p[MAXN], r[MAXN];
int Find(int x)
{
    if (p[x] == x) return x;
    int root = Find(p[x]);
    r[x] += r[p[x]];
    return p[x] = root;
}
bool Union(int i, int j, int num)
{
    int x = Find(i), y = Find(j);
    if (x == y) return r[i]+num == r[j];
    if (x < y) {
        p[y] = x;
        r[y] = r[i]+num-r[j];
    } else {
        p[x] = y;
        r[x] = r[j]-r[i]-num;
    }
    return true;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d%d", &n, &m)) {
        FOR(i,1,n+1) p[i] = i;
        memset(r+1, 0, sizeof(int) * (n+1));
        int ans = 0;
        while (m--) {
            int x, y, num; scanf("%d%d%d", &x, &y, &num);
            if (!Union(x,y+1,num)) ans++;
        }
        printf("%d\n", ans);
    }


    return 0;
}


















































































