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

int T, n, X, Y, MAX, h[MAXN<<1], t[MAXN<<1];
struct node {
    int x[2], h;
    bool operator<(const node& o) const { return h < o.h; }
} a[1024];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d", &n, &X, &Y, &MAX);
        REP(i,n) scanf("%d%d%d", &a[i].x[0], &a[i].x[1], &a[i].h);
        sort(a, a+n);
        memset(h, 0, sizeof(h));
        memset(t, 0, sizeof(t));
        REP(i,n) {
            int l = a[i].x[0] + MAXN, r = a[i].x[1] + MAXN;
            int lt = t[l], rt = t[r];
            if (a[i].h-h[l] <= MAX || a[i].h-h[r] <= MAX) {
                if (a[i].h-h[l] > MAX) ROF(j,l,r) t[j] = rt+r-j + a[i].h-h[r];
                else if (a[i].h-h[r] > MAX) FOR(j,l,r) t[j] = lt+j-l + a[i].h-h[l];
                else {
                    FOR(j,l,r) t[j] = lt+j-l + a[i].h-h[l];
                    ROF(j,l,r) t[j] = min(t[j], rt+r-j + a[i].h-h[r]);
                }
                FOR(j,l,r) h[j] = a[i].h;
            }
        }
        printf("%d\n", Y - h[X+MAXN] + t[X+MAXN]);
    }

    return 0;
}




















































































