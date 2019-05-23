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
const int MAXN = 1e5+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 10007;

#define ls x<<1
#define rs x<<1|1
struct node {
    int l,r;
    LL sum[4],lazy[4];
    void update(int op, LL k)
    {
        LL tmp;
        switch (op) {
        case 1:
            lazy[1] = (lazy[1]+k)%MOD;
            sum[3] += 3*k*sum[2] + 3*k*k*sum[1] + k*k*k*(r-l+1);
            sum[2] += 2*k*sum[1] + k*k*(r-l+1);
            sum[1] += k*(r-l+1);
            FOR(i,1,3) sum[i] %= MOD;
            break;
        case 2:
            lazy[1] = lazy[1]*k%MOD;
            lazy[2] = lazy[2]*k%MOD;
            tmp = k;
            FOR(i,1,3) sum[i] = sum[i]*tmp%MOD, tmp *= k;
            break;
        case 3:
            lazy[1] = 0;
            lazy[2] = 1;
            lazy[3] = k;
            tmp = k;
            FOR(i,1,3) sum[i] = tmp*(r-l+1)%MOD, tmp *= k;
            break;
        }
    }
} tree[MAXN<<2];
void push_up(int x)
{
    FOR(i,1,3) tree[x].sum[i] = (tree[ls].sum[i] + tree[rs].sum[i]) % MOD;
}
void push_down(int x)
{
    ROF(i,1,3) {
        LL& t = tree[x].lazy[i];
        LL tag = i==2 ? 1 : 0;
        if (t != tag) {
            tree[ls].update(i,t);
            tree[rs].update(i,t);
            t = tag;
        }
    }
}
void build(int x, int l, int r)
{
    tree[x].l = l, tree[x].r = r;
    FOR(i,1,3) tree[x].sum[i] = tree[x].lazy[i] = 0;
    tree[x].lazy[2] = 1;
    if (l<r) {
        int m = (l+r)>>1;
        build(ls,l,m);
        build(rs,m+1,r);
    }
}
void update(int x, int op, int l, int r, int val)
{
    int L = tree[x].l, R = tree[x].r;
    if (l <= L && R <= r) {
        tree[x].update(op,val);
    } else {
        push_down(x);
        int m = (L+R)>>1;
        if (l<=m) update(ls,op,l,r,val);
        if (m<r)  update(rs,op,l,r,val);
        push_up(x);
    }
}
LL query(int x, int l, int r, int p)
{
    int L = tree[x].l, R = tree[x].r;
    if (l <= L && R <= r) {
        return tree[x].sum[p];
    } else {
        push_down(x);
        LL ans = 0;
        int m = (L+R)>>1;
        if (l<=m) ans += query(ls,l,r,p);
        if (m<r)  ans += query(rs,l,r,p);
        return ans % MOD;
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int n, m, op, l, r, val;
    while (scanf("%d%d", &n, &m) == 2 && n && m) {
        build(1,1,n);
        while (m--) {
            scanf("%d%d%d%d", &op,&l,&r,&val);
            if (op != 4) update(1,op,l,r,val);
            else printf("%I64d\n", query(1,l,r,val));
        }
    }

    return 0;
}












































































