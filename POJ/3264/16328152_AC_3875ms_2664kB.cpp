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

#define ls x<<1
#define rs x<<1|1
struct node {
    int l,r,mi,ma;
    void update(int x)
    {

    }
} tree[MAXN<<2];
void push_up(int x)
{
    tree[x].mi = min(tree[ls].mi, tree[rs].mi);
    tree[x].ma = max(tree[ls].ma, tree[rs].ma);
}
void build(int x, int l, int r)
{
    tree[x].l = l, tree[x].r = r;
    if (l == r) scanf("%d", &tree[x].mi), tree[x].ma = tree[x].mi;
    else {
        int m = (l+r)>>1;
        build(ls,l,m);
        build(rs,m+1,r);
        push_up(x);
    }
}
int qmi(int x, int l, int r)
{
    int L = tree[x].l, R = tree[x].r;
    if (l <= L && R <= r) return tree[x].mi;
    else {
        int m = (L+R)>>1;
        int ans = INF;
        if (l<=m) ans = min(ans,qmi(ls,l,r));
        if (m<r) ans = min(ans,qmi(rs,l,r));
        return ans;
    }
}
int qma(int x, int l, int r)
{
    int L = tree[x].l, R = tree[x].r;
    if (l <= L && R <= r) return tree[x].ma;
    else {
        int m = (L+R)>>1;
        int ans = 0;
        if (l<=m) ans = max(ans,qma(ls,l,r));
        if (m<r) ans = max(ans,qma(rs,l,r));
        return ans;
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int n, q; scanf("%d%d", &n, &q);
    build(1,1,n);
    while (q--) {
        int x, y; scanf("%d%d", &x, &y);
        printf("%d\n", qma(1,x,y)-qmi(1,x,y));
    }

    return 0;
}












































































