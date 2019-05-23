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

int to[MAXN], f[MAXN], nxt[MAXN], tot;
inline void add(int u, int v)
{
    to[tot] = v;
    nxt[tot] = f[u];
    f[u] = tot++;
}

int ll[MAXN], rr[MAXN], cnt;
void dfs(int x)
{
    ll[x] = ++cnt;
    for (int i = f[x]; ~i; i = nxt[i]) dfs(to[i]);
    rr[x] = cnt;
}

#define ls x<<1
#define rs x<<1|1
struct node {
    int l,r,num,lazy;
    void update(int x)
    {
        num = x;
        lazy = x;
    }
} tree[MAXN<<2];
void push_down(int x)
{
    int& t = tree[x].lazy;
    if (~t) {
        tree[ls].update(t);
        tree[rs].update(t);
        t = -1;
    }
}
void build(int x, int l, int r)
{
    tree[x].l = l, tree[x].r = r;
    tree[x].update(-1);
    if (r-l) {
        int m = (l+r)>>1;
        build(ls,l,m);
        build(rs,m+1,r);
    }
}
void update(int x, int l, int r, int val)
{
    int L = tree[x].l, R = tree[x].r;
    if (l <= L && R <= r) tree[x].update(val);
    else {
        push_down(x);
        int m = (L+R)>>1;
        if (l<=m) update(ls,l,r,val);
        if (m<r)  update(rs,l,r,val);
    }
}
int query(int x, int k)
{
    int L = tree[x].l, R = tree[x].r;
    if (L == R) return tree[x].num;
    else {
        push_down(x);
        int m = (L+R)>>1;
        if (k<=m) return query(ls,k);
        else return query(rs,k);
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T, n, q, x, y;
    char op[10];
    scanf("%d", &T);
    FOR(kase,1,T) {
        printf("Case #%d:\n", kase);
        memset(f,-1,sizeof(f));
        tot = 0;
        scanf("%d", &n);
        LL sum = 0;
        REP(i,n-1) {
            int u,v; scanf("%d%d", &u, &v);
            add(v,u);
            sum += u;
        }
        cnt = 0;
        dfs((LL)n*(n+1)/2-sum);
        build(1,1,n);
        scanf("%d", &q);
        while (q--) {
            scanf("%s", op);
            if (op[0] == 'C') {
                scanf("%d", &x);
                printf("%d\n", query(1,ll[x]));
            } else {
                scanf("%d%d", &x, &y);
                update(1,ll[x],rr[x],y);
            }
        }
    }

    return 0;
}












































































