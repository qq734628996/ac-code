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

struct fhq_treap {
    #define lt T[x].ls
    #define rt T[x].rs
    int root,tot,tmp;
    struct node {
        int rnd,sum,ma,sz,add,rev,ls,rs;
    } T[MAXN];
    void build(int& x, int val) { T[x=++tot] = node{rand()<<15|rand(),val,val,1}; }
    void addone(int x, int val) { if (x) T[x].sum+=val, T[x].ma+=val, T[x].add+=val; }
    void revone(int x) { T[x].rev ^= 1, swap(lt,rt); }
    void init()
    {
        srand(19981111);
        root = tot = 0;
        T[0] = node{-INF,-INF,-INF};
    }
    void up(int x)
    {
        if (x) {
            T[x].ma = max(T[x].sum, max(T[lt].ma, T[rt].ma));
            T[x].sz = T[lt].sz + T[rt].sz + 1;
        }
    }
    void down(int x)
    {
        if (x) {
            if (T[x].add) addone(lt,T[x].add), addone(rt,T[x].add);
            if (T[x].rev) revone(lt), revone(rt);
            T[x].add = T[x].rev = 0;
        }
    }
    void Merge(int& x, int l, int r)
    {
        if (!l || !r) x=l+r;
        else if (T[l].rnd<T[r].rnd) down(x=l), Merge(rt,rt,r), up(x);
        else down(x=r), Merge(lt,l,lt), up(x);
    }
    void build(int n)
    {
        while (n--) {
            build(tmp,0);
            Merge(root,root,tmp);
        }
    }
    void split(int x, int& l, int& r, int k)
    {
        if (!k) l=0, r=x;
        else if (k==T[x].sz) l=x, r=0;
        else if (k<=T[lt].sz) down(r=x), split(lt,l,lt,k), up(x);
        else down(l=x), split(rt,rt,r,k-T[lt].sz-1), up(x);
    }
    void add(int l, int r, int val)
    {
        int x,y,z;
        split(root,x,z,r), split(x,x,y,l-1);
        addone(y,val);
        Merge(x,x,y), Merge(root,x,z);
    }
    void Reverse(int l, int r)
    {
        int x,y,z;
        split(root,x,z,r), split(x,x,y,l-1);
        revone(y);
        Merge(x,x,y), Merge(root,x,z);
    }
    int query_ma(int l, int r)
    {
        int x,y,z;
        split(root,x,z,r), split(x,x,y,l-1);
        int ans = T[y].ma;
        Merge(x,x,y), Merge(root,x,z);
        return ans;
    }
};

fhq_treap solve;
int n,m,x,y,z,op;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d%d", &n,&m);
    solve.init();
    solve.build(n);
    while (m--) {
        scanf("%d%d%d", &op,&x,&y);
        switch (op) {
        case 1: scanf("%d", &z), solve.add(x,y,z);
            break;
        case 2: solve.Reverse(x,y);
            break;
        case 3: printf("%d\n", solve.query_ma(x,y));
            break;
        }
    }

    return 0;
}











































































