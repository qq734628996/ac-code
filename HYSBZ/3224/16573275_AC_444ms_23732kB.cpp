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

struct Istream {
    char b[20<<20],*i,*e;
    Istream(FILE* in):i(b),e(b+fread(b,sizeof(*b),sizeof(b)-1,in)) {}
    Istream& operator>>(int& val) {
        LL sgn = 1;
        for (; !isdigit(*i); i++) if (*i == '-') sgn *= -1;
        for (val = 0; isdigit(*i); i++) val = (val<<3)+(val<<1)+*i-'0';
        return val*=sgn,*this;
    }
} kin(stdin);

struct fhq_treap {
    #define lt T[x].ls
    #define rt T[x].rs
    int root,tot,tmp;
    struct node {
        int rnd,sum,sz,ls,rs;
    } T[MAXN];
    void init()
    {
        srand(19981111);
        root = tot = 0;
        T[0].rnd = T[0].sum = INF;
    }
    void build(int& x, int val) { T[x=++tot] = node{rand()<<15|rand(),val,1}; }
    void up(int x) { if (x) T[x].sz = T[lt].sz+T[rt].sz+1; }
    void Merge(int& x, int l, int r)
    {
        if (!l || !r) x = l+r;
        else if (T[l].rnd<T[r].rnd) x=l, Merge(rt,rt,r), up(x);
        else x=r, Merge(lt,l,lt), up(x);
    }
    void split(int x, int& l, int& r, int k)
    {
        if (!k) l=0, r=x;
        else if (k==T[x].sz) l=x, r=0;
        else if (k<=T[lt].sz) r=x, split(lt,l,lt,k), up(x);
        else l=x, split(rt,rt,r,k-T[lt].sz-1), up(x);
    }
    int Rank(int x, int val)
    {
        if (!x) return 0;
        if (T[x].sum>=val) return Rank(lt,val);
        return T[lt].sz+1+Rank(rt,val);
    }
    void Insert(int val)
    {
        int x,y,rk = Rank(root,val);
        split(root,x,y,rk);
        build(tmp,val);
        Merge(x,x,tmp); Merge(root,x,y);
    }
    void del(int val)
    {
        int x,y,z,rk = Rank(root,val);
        split(root,x,y,rk+1); split(x,x,z,rk);
        Merge(root,x,y);
    }
    int Kth(int k)
    {
        int x,y,z;
        split(root,x,y,k); split(x,x,z,k-1);
        int ans = T[z].sum;
        Merge(x,x,z); Merge(root,x,y);
        return ans;
    }
    int pre(int val)
    {
        int x,y,z,rk = Rank(root,val);
        split(root,x,y,rk); split(x,x,z,rk-1);
        int ans = T[z].sum;
        Merge(x,x,z); Merge(root,x,y);
        return ans;
    }
    int succ(int val)
    {
        int x,y,z,rk = Rank(root,val+1);
        split(root,x,y,rk+1); split(x,x,z,rk);
        int ans = T[z].sum;
        Merge(x,x,z); Merge(root,x,y);
        return ans;
    }
};

fhq_treap solve;
int n,op,x;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    kin >> n;
    solve.init();
    while (n--) {
        kin >> op >> x;
        switch (op) {
        case 1: solve.Insert(x);
            break;
        case 2: solve.del(x);
            break;
        case 3: printf("%d\n", solve.Rank(solve.root,x)+1);
            break;
        case 4: printf("%d\n", solve.Kth(x));
            break;
        case 5: printf("%d\n", solve.pre(x));
            break;
        case 6: printf("%d\n", solve.succ(x));
            break;
        }
    }

    return 0;
}











































































