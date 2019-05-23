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
const int MAXN = 5e4+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 10007;

#define ls x<<1
#define rs x<<1|1
struct node {
    int l,r,sum,lazy;
    void update(int x)
    {
        lazy = x;
        sum = x*(r-l+1);
    }
} tree[MAXN<<2];
void push_up(int x)
{
    tree[x].sum = tree[ls].sum + tree[rs].sum;
}
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
    tree[x].sum = 0, tree[x].lazy = -1;
    if (l<r) {
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
        push_up(x);
    }
}
int query(int x, int l, int r)
{
    int L = tree[x].l, R = tree[x].r;
    if (l <= L && R <= r) return tree[x].sum;
    else {
        push_down(x);
        int ans = 0;
        int m = (L+R)>>1;
        if (l<=m) ans += query(ls,l,r);
        if (m<r)  ans += query(rs,l,r);
        return ans;
    }
}

int T,n,m,op,x,y,kase;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n,&m);
        build(1,1,n);
        while (m--) {
            scanf("%d%d%d", &op,&x,&y);
            if (op == 1) {
                x++;
                int L,R;
                int l = x, r = n;
                while (l<r) {
                    int m = (l+r)>>1;
                    if (m-x+1-query(1,x,m) < 1) l = m+1;
                    else r = m;
                }
                L = l;
                r = n;
                y = min(y, n-L+1-query(1,L,n));
                while (l<r) {
                    int m = (l+r)>>1;
                    if (m-L+1-query(1,L,m) < y) l = m+1;
                    else r = m;
                }
                R = r;
                if (R-L+1-query(1,L,R) == 0) puts("Can not put any one.");
                else printf("%d %d\n", L-1, R-1);
                update(1,L,R,1);
            } else {
                x++, y++;
                printf("%d\n", query(1,x,y));
                update(1,x,y,0);
            }
        }
        puts("");
    }

    return 0;
}












































































