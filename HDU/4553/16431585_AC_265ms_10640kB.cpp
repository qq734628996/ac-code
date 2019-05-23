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
    int l,r,pre[2],suf[2],ma[2],lazy;
    void update(int x)
    {
        lazy = x;
        switch (x) {
        case 0:
            REP(i,2) pre[i] = suf[i] = ma[i] = r-l+1;
            break;
        case 1:
            pre[0] = suf[0] = ma[0] = 0;
            pre[1] = suf[1] = ma[1] = r-l+1;
            break;
        case 2:
            REP(i,2) pre[i] = suf[i] = ma[i] = 0;
            break;
        }
    }
} tree[MAXN<<2];
void push_up(int x)
{
    REP(i,2) {
        tree[x].pre[i] = tree[ls].pre[i];
        if (tree[x].pre[i] == tree[ls].r-tree[ls].l+1) tree[x].pre[i] += tree[rs].pre[i];
        tree[x].suf[i] = tree[rs].suf[i];
        if (tree[x].suf[i] == tree[rs].r-tree[rs].l+1) tree[x].suf[i] += tree[ls].suf[i];
        tree[x].ma[i] = max(tree[ls].suf[i]+tree[rs].pre[i], max(tree[ls].ma[i], tree[rs].ma[i]));
    }
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
    tree[x].lazy = -1;
    REP(i,2) tree[x].pre[i] = tree[x].suf[i] = tree[x].ma[i] = r-l+1;
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
int query(int x, int k, int val)
{
    int L = tree[x].l, R = tree[x].r;
    if (L==R) return L;
    push_down(x);
    int m = (L+R)>>1;
    if (tree[ls].ma[k] >= val) return query(ls,k,val);
    else if (tree[ls].suf[k]+tree[rs].pre[k] >= val) return m-tree[ls].suf[k]+1;
    else return query(rs,k,val);
}

int T,n,m,x,y;
char op[10];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    FOR(kase,1,T) {
        printf("Case %d:\n", kase);
        scanf("%d%d", &n,&m);
        build(1,1,n);
        while (m--) {
            scanf("%s", op);
            switch (op[0]) {
            case 'D':
                scanf("%d", &x);
                if (tree[1].ma[0] < x) puts("fly with yourself");
                else {
                    int t = query(1,0,x);
                    update(1,t,t+x-1,1);
                    printf("%d,let's fly\n", t);
                }
                break;
            case 'N':
                scanf("%d", &x);
                if (tree[1].ma[0] >= x) {
                    int t = query(1,0,x);
                    update(1,t,t+x-1,2);
                    printf("%d,don't put my gezi\n", t);
                } else if (tree[1].ma[1] >= x) {
                    int t = query(1,1,x);
                    update(1,t,t+x-1,2);
                    printf("%d,don't put my gezi\n", t);
                } else puts("wait for me");
                break;
            case 'S':
                scanf("%d%d", &x,&y);
                update(1,x,y,0);
                puts("I am the hope of chinese chengxuyuan!!");
                break;
            }
        }
    }

    return 0;
}












































































