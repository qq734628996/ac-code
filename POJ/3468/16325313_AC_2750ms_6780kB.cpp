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
const int MAXN = 1e5+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 1000000007;

struct node {
    int l, r;
    LL sum, lazy;
    void update(LL x)
    {
        sum += x*(r-l+1);
        lazy += x;
    }
} tree[MAXN<<2];
void push_up(int x)
{
    tree[x].sum = tree[x<<1].sum + tree[x<<1|1].sum;
}
void push_down(int x)
{
    LL& lazyval = tree[x].lazy;
    if (lazyval) {
        tree[x<<1].update(lazyval);
        tree[x<<1|1].update(lazyval);
        lazyval = 0;
    }
}
void build(int x, int l, int r)
{
    tree[x].l = l, tree[x].r = r;
    tree[x].lazy = 0;
    if (l == r) scanf("%I64d", &tree[x].sum);
    else {
        int m = (l+r)>>1;
        build(x<<1,l,m);
        build(x<<1|1,m+1,r);
        push_up(x);
    }
}
void update(int x, int l, int r, LL val)
{
    int L = tree[x].l, R = tree[x].r;
    if (l <= L && R <= r) tree[x].update(val);
    else {
        push_down(x);
        int m = (L+R)>>1;
        if (l<=m) update(x<<1,l,r,val);
        if (m<r) update(x<<1|1,l,r,val);
        push_up(x);
    }
}
LL query(int x, int l, int r)
{
    int L = tree[x].l, R = tree[x].r;
    if (l <= L && R <= r) return tree[x].sum;
    else {
        push_down(x);
        LL ans = 0;
        int m = (L+R)>>1;
        if (l<=m) ans += query(x<<1,l,r);
        if (m<r) ans += query(x<<1|1,l,r);
        return ans;
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int n,q; scanf("%d%d", &n, &q);
    build(1,1,n);
    char op[10];
    while (q--) {
        scanf("%s", op);
        int x,y,z;
        if (op[0] == 'Q') {
            scanf("%d%d", &x, &y);
            printf("%I64d\n", query(1,x,y));
        } else {
            scanf("%d%d%d", &x, &y, &z);
            update(1,x,y,z);
        }
    }

    return 0;
}












































































