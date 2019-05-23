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

#define ls x<<1
#define rs x<<1|1
struct node {
    int l,r;
    LL sum;
} tree[MAXN<<2];
void push_up(int x)
{
    tree[x].sum = tree[ls].sum + tree[rs].sum;
}
void build(int x, int l, int r)
{
    tree[x].l = l, tree[x].r = r;
    if (l == r) scanf("%I64d", &tree[x].sum);
    else {
        int m = (l+r)>>1;
        build(ls,l,m);
        build(rs,m+1,r);
        push_up(x);
    }
}
void update(int x, int l, int r)
{
    int L = tree[x].l, R = tree[x].r;
    if (tree[x].sum == R-L+1) return;
    if (L == R) tree[x].sum = (LL)sqrt(tree[x].sum);
    else {
        int m = (L+R)>>1;
        if (l<=m) update(ls,l,r);
        if (m<r)  update(rs,l,r);
        push_up(x);
    }
}
LL query(int x, int l, int r)
{
    int L = tree[x].l, R = tree[x].r;
    if (l <= L && R <= r) return tree[x].sum;
    else {
        LL ans = 0;
        int m = (L+R)>>1;
        if (l<=m) ans += query(ls,l,r);
        if (m<r)  ans += query(rs,l,r);
        return ans;
    }
}

int n, kase, q, x, y, z;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d", &n)) {
        printf("Case #%d:\n", ++kase);
        build(1,1,n);
        scanf("%d", &q);
        while (q--) {
            scanf("%d%d%d", &x,&y,&z);
            if (y>z) swap(y,z);
            if (!x) update(1,y,z);
            else printf("%I64d\n", query(1,y,z));
        }
        puts("");
    }

    return 0;
}












































































