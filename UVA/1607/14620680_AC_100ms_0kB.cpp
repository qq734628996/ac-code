#include <bits/stdc++.h>
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
typedef pair<int, int> pii;
const int MAXN  = 2e5+5, INF = ~0U>>1, MOD = ~0U>>1;

int T, n, m, l, r, mi, res[2];

struct gate {
    int a, b, o;
} g[MAXN];

int f(int x) //递归版超时，须用结构体迭代
{
    FOR(i,1,m) {
        int x1 = g[i].a>0 ? g[g[i].a].o : -g[i].a > x;
        int x2 = g[i].b>0 ? g[g[i].b].o : -g[i].b > x;
        g[i].o = !(x1 && x2);
    }
    return g[m].o;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        FOR(i,1,m) scanf("%d%d", &g[i].a, &g[i].b);
        res[0] = f(0);
        res[1] = f(n);
        if (res[0] == res[1]) REP(i,n) putchar('0');
        else {
            l = 1; r = n;
            while (l < r) {
                mi = l + (r-l)/2;
                if (f(mi) == res[1]) r = mi;
                else l = mi+1;
            }
            FOR(i,1,l-1) putchar('0');
            putchar('x');
            FOR(i,l+1,n) putchar('1');
        }
        puts("");
    }

    return 0;
}











































































