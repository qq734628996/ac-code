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
const int MAXN = 2e5+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 1000000007;

struct node {
    int l,r,maxv,lazy;
    void update(int x)
    {
        maxv = x;
        lazy = x;
    }
} tree[MAXN<<2];
void push_up(int x)
{
    tree[x].maxv = max(tree[x<<1].maxv, tree[x<<1|1].maxv);
}
void push_down(int x)
{
    int& lazyval = tree[x].lazy;
    if (~lazyval) {
        tree[x<<1].update(lazyval);
        tree[x<<1|1].update(lazyval);
        lazyval = -1;
    }
}
void build(int x, int l, int r)
{
    tree[x].l = l, tree[x].r = r;
    tree[x].lazy = -1;
    if (l == r) scanf("%d", &tree[x].maxv);
    else {
        int m = (l+r)>>1;
        build(x<<1,l,m);
        build(x<<1|1,m+1,r);
        push_up(x);
    }
}
void update(int x, int l, int r, int val)
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
int query(int x, int l, int r)
{
    int L = tree[x].l, R = tree[x].r;
    if (l <= L && R <= r) return tree[x].maxv;
    else {
        push_down(x);
        int ans = 0;
        int m = (L+R)>>1;
        if (l<=m) ans = max(ans, query(x<<1,l,r));
        if (m<r) ans = max(ans, query(x<<1|1,l,r));
        return ans;
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int n, q;
    char op[10];
    while (scanf("%d%d", &n, &q) == 2) {
        build(1,1,n);
        while (q--) {
            int x, y;
            scanf("%s%d%d", op, &x, &y);
            if (op[0] == 'Q') printf("%d\n", query(1,x,y));
            else update(1,x,x,y);
        }
    }

    return 0;
}












































































