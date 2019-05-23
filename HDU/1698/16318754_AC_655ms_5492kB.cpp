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
    int l,r,sum,lazy;
    void update(int x)
    {
        sum = x*(r-l+1);
        lazy = x;
    }
} tree[MAXN<<2];
void push_up(int x)
{
    tree[x].sum = tree[x<<1].sum + tree[x<<1|1].sum;
}
void push_down(int x)
{
    int& lazyval = tree[x].lazy;
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
    if (l == r) {
        tree[x].sum = 1;
    } else {
        int m = (l+r)/2;
        build(x<<1, l, m);
        build(x<<1|1, m+1, r);
        push_up(x);
    }
}
void update(int x, int l, int r, int val)
{
    int L = tree[x].l, R = tree[x].r;
    if (l <= L && R <= r) {
        tree[x].update(val);
    } else {
        push_down(x);
        int m = (L+R)/2;
        if (l <= m) update(x<<1,l,r,val);
        if (m < r) update(x<<1|1,l,r,val);
        push_up(x);
    }
}
int query(int x, int l, int r)
{
    int L = tree[x].l, R = tree[x].r;
    if (l <= L && R <= r) {
        return tree[x].sum;
    } else {
        push_down(x);
        int ans = 0;
        int m = (L+R)/2;
        if (l <= m) ans += query(x<<1,l,r);
        if (m < r) ans += query(x<<1|1,l,r);
        return ans;
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    FOR(kase,1,T) {
        int n, q; scanf("%d%d", &n, &q);
        build(1,1,n);
        while (q--) {
            int x, y, z; scanf("%d%d%d", &x, &y, &z);
            update(1,x,y,z);
        }
        printf("Case %d: The total value of the hook is %d.\n", kase, query(1,1,n));
    }

    return 0;
}












































































