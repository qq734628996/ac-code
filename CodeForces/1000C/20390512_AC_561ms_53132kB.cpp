#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n) cout<<A[i]<<(i==n-1?'\n':' '); }
#define SHOW2(A,m,n) { REP(j,m) SHOW1(A[j],n) }
#define pb push_back
#define fi first
#define se second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)((x).size())
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const int INF = 0x3f3f3f3f, MOD = 1000000007;
const double PI = acos(-1), EPS = 1e-15;
const int MAXN = 4e5+9, MAXM = 3e3+9;

struct node {
    int l, r;
    LL sum, lazy;
    void update(LL x)
    {
        sum += x*(r-l+1);
        lazy += x;
    }
} tree[MAXN<<2];
void push_up(int x)
{
    tree[x].sum = tree[x<<1].sum + tree[x<<1|1].sum;
}
void push_down(int x)
{
    LL& lazyval = tree[x].lazy;
    if (lazyval) {
        tree[x<<1].update(lazyval);
        tree[x<<1|1].update(lazyval);
        lazyval = 0;
    }
}
void build(int x, int l, int r)
{
    tree[x].l = l, tree[x].r = r;
    tree[x].lazy = 0;
    if (l == r) tree[x].sum=0;
    else {
        int m = (l+r)>>1;
        build(x<<1,l,m);
        build(x<<1|1,m+1,r);
        push_up(x);
    }
}
void update(int x, int l, int r, LL val)
{
    int L = tree[x].l, R = tree[x].r;
    if (l <= L && R <= r) tree[x].update(val);
    else {
        push_down(x);
        int m = (L+R)>>1;
        if (l<=m) update(x<<1,l,r,val);
        if (m<r) update(x<<1|1,l,r,val);
        push_up(x);
    }
}
LL query(int x, int l, int r)
{
    int L = tree[x].l, R = tree[x].r;
    if (l <= L && R <= r) return tree[x].sum;
    else {
        push_down(x);
        LL ans = 0;
        int m = (L+R)>>1;
        if (l<=m) ans += query(x<<1,l,r);
        if (m<r) ans += query(x<<1|1,l,r);
        return ans;
    }
}
LL n,a[MAXN], b[MAXN];
vector<LL> V;
int ID(LL x) { return lower_bound(ALL(V),x)-V.begin()+1; }
LL ans[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n)==1) {
        V.clear();
        REP(i,n) scanf("%lld%lld", &a[i], &b[i]), b[i]++;
        REP(i,n) V.pb(a[i]), V.pb(b[i]);
        sort(ALL(V)); V.erase(unique(ALL(V)), V.end());
        build(1,1,SZ(V)+1);
        REP(i,n) {
            update(1,ID(a[i]),ID(b[i])-1,1);
        }
        memset(ans,0,sizeof(ans));
        REP(i,SZ(V)-1) {
            ans[query(1,i+1,i+1)]+=V[i+1]-V[i];
        }
        FOR(i,1,n) printf("%lld%c", ans[i],i==n?'\n':' ');
    }

    return 0;
}

































