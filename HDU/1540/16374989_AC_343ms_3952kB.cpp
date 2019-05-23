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

int n,m;
char op[10];

#define ls x<<1
#define rs x<<1|1
struct node {
    int l,r,pre,suf,ma;
} tree[MAXN<<2];
void push_up(int x)
{
    tree[x].pre = tree[ls].pre;
    if (tree[x].pre == tree[ls].r-tree[ls].l+1) tree[x].pre += tree[rs].pre;
    tree[x].suf = tree[rs].suf;
    if (tree[x].suf == tree[rs].r-tree[rs].l+1) tree[x].suf += tree[ls].suf;
    tree[x].ma = max(tree[ls].suf+tree[rs].pre, max(tree[ls].ma, tree[rs].ma));
}
void build(int x, int l, int r)
{
    tree[x].l = l, tree[x].r = r;
    tree[x].pre = tree[x].suf = tree[x].ma = r-l+1;
    if (l != r) {
        int m = (l+r)>>1;
        build(ls,l,m);
        build(rs,m+1,r);
    }
}
void update(int x, int k, int val)
{
    int L = tree[x].l, R = tree[x].r;
    if (L == R) tree[x].pre = tree[x].suf = tree[x].ma = val;
    else {
        int m = (L+R)>>1;
        if (k<=m) update(ls,k,val);
        else update(rs,k,val);
        push_up(x);
    }
}
int query(int x, int k)
{
    int L = tree[x].l, R = tree[x].r;
    if (L == R) return tree[x].ma;
    else {
        int m = (L+R)>>1;
        if (k<=m) {
            if (k > m-tree[ls].suf) return tree[ls].suf+tree[rs].pre;
            else return query(ls,k);
        } else {
            if (k < m+1+tree[rs].pre) return tree[ls].suf+tree[rs].pre;
            else return query(rs,k);
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d", &n, &m) == 2) {
        build(1,1,n);
        stack<int> S;
        while (m--) {
            scanf("%s", op);
            if (op[0] == 'R') {
                if (!S.empty()) {
                    int x = S.top(); S.pop();
                    update(1,x,1);
                }
            } else {
                int x; scanf("%d", &x);
                if (op[0] == 'D') {
                    S.push(x);
                    update(1,x,0);
                } else printf("%d\n", query(1,x));
            }
        }
    }

    return 0;
}












































































