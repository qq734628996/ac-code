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
const int MAXN = 1e5+9, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 10007;

struct splay_tree {
    struct node {
        int val,ma,add,rev,sz,son[2];
        void init(int x)
        {
            val = ma = x, sz = 1;
            add = rev = son[0] = son[1] = 0;
        }
        void update(int x)
        {
            val += x, ma += x, add += x;
        }
    } T[MAXN];
    int fa[MAXN],root;

    void push_up(int x)
    {
        T[x].ma = T[x].val, T[x].sz = 1;
        REP(i,2) {
            int son = T[x].son[i];
            if (son) {
                T[x].ma = max(T[x].ma, T[son].ma);
                T[x].sz += T[son].sz;
            }
        }
    }

    void push_down(int x)
    {
        if (x) {
            if (T[x].add) {
                REP(i,2) if (T[x].son[i]) T[T[x].son[i]].update(T[x].add);
                T[x].add = 0;
            }
            if (T[x].rev) {
                REP(i,2) if (T[x].son[i]) T[T[x].son[i]].rev ^= 1;
                swap(T[x].son[0], T[x].son[1]);
                T[x].rev = 0;
            }
        }
    }

    void Splay(int x, int goal)
    {
        if (x == goal) return;
        while (fa[x] != goal) {
            int y = fa[x], z = fa[y];
            push_down(z), push_down(y), push_down(x);
            int rx = T[y].son[0]==x, ry = T[z].son[0]==y;
            if (z == goal) Rotate(x,rx);
            else {
                if (rx == ry) Rotate(y,ry);
                else Rotate(x,rx);
                Rotate(x,ry);
            }
        }
        push_up(x);
        if (!goal) root = x;
    }

    int Select(int pos)
    {
        int u = root;
        push_down(u);
        while (T[T[u].son[0]].sz != pos) {
            if (pos < T[T[u].son[0]].sz) u = T[u].son[0];
            else {
                pos -= T[T[u].son[0]].sz+1;
                u = T[u].son[1];
            }
            push_down(u);
        }
        return u;
    }

    void update(int L, int R, int val)
    {
        int u = Select(L-1), v = Select(R+1);
        Splay(u,0);
        Splay(v,u);
        T[T[v].son[0]].update(val);
    }

    void Reverse(int L, int R)
    {
        int u = Select(L-1), v = Select(R+1);
        Splay(u,0);
        Splay(v,u);
        T[T[v].son[0]].rev ^= 1;
    }

    int query(int L, int R)
    {
        int u = Select(L-1), v = Select(R+1);
        Splay(u,0);
        Splay(v,u);
        return T[T[v].son[0]].ma;
    }

    void Rotate(int x, int kind)
    {
        int y = fa[x], z = fa[y];
        T[y].son[!kind] = T[x].son[kind], fa[T[x].son[kind]] = y;
        T[x].son[kind] = y, fa[y] = x;
        T[z].son[T[z].son[1]==y] = x, fa[x] = z;
        push_up(y);
    }

    int build(int L, int R)
    {
        if (L > R) return 0;
        if (L == R) return L;
        int M = (L+R)>>1, ls, rs;
        T[M].son[0] = ls = build(L,M-1);
        T[M].son[1] = rs = build(M+1,R);
        fa[ls] = fa[rs] = M;
        push_up(M);
        return M;
    }

    void init(int n)
    {
        T[0].init(-INF), T[1].init(-INF), T[n+2].init(-INF);
        FOR(i,2,n+1) T[i].init(0);
        root = build(1,n+2), fa[root] = 0;
        fa[0] = 0, T[0].son[1] = root, T[0].sz = 0;
    }
};

splay_tree solve;
int n,m,op,L,R,v;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d%d", &n,&m);
    solve.init(n);
    while (m--) {
        scanf("%d%d%d", &op,&L,&R);
        if (op == 1) scanf("%d", &v), solve.update(L,R,v);
        else if (op == 2) solve.Reverse(L,R);
        else printf("%d\n", solve.query(L,R));
    }

    return 0;
}











































































