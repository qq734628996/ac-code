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
const int MAXN = 8e3+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 1000000007;

#define ls x<<1
#define rs x<<1|1
struct node {
    int l,r,lazy;
    void update(int x) { lazy = x; }
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
    tree[x].lazy = -1;
    if (l != r) {
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
        if (m<r) update(rs,l,r,val);
    }
}
int query(int x, int l, int r)
{
    int L = tree[x].l, R = tree[x].r;
    if (l <= L && R <= r) return tree[x].lazy;
    else {
        push_down(x);
        int m = (L+R)>>1;
        if (l<=m) return query(ls,l,r);
        else return query(rs,l,r);
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int n;
    while (~scanf("%d", &n)) {
        build(1,1,8000);
        FOR(i,1,n) {
            int x,y,z; scanf("%d%d%d", &x,&y,&z);
            update(1,x+1,y,z);
        }
        map<int, int> mp;
        int pre = -1;
        FOR(i,1,8000) {
            int t = query(1,i,i);
            if (~t) {
                if (t != pre) {
                    pre = t;
                    if (mp.count(t)) mp[t]++;
                    else mp[t] = 1;
                }
            } else pre = -1;
        }
        for (map<int,int>::iterator it = mp.begin(); it != mp.end(); it++) {
            printf("%d %d\n", it->fi, it->se);
        }
        puts("");
    }

    return 0;
}












































































