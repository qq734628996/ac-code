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
const int MAXN = 1e4+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 10007;

struct Line {
    double x,y1,y2;
    int sign;
    bool operator<(const Line& o) const { return x < o.x; }
} line[MAXN];
vector<double> Y;
int ID(double y) { return lower_bound(ALL(Y),y)-Y.begin(); }

#define ls x<<1
#define rs x<<1|1
struct node {
    int l,r,cover;
    double len;
} tree[MAXN<<2];
void push_up(int x)
{
    int L = tree[x].l, R = tree[x].r;
    if (tree[x].cover) tree[x].len = Y[R]-Y[L-1];
    else if (L == R) tree[x].len = 0;
    else tree[x].len = tree[ls].len + tree[rs].len;
}
void build(int x, int l, int r)
{
    tree[x].l = l, tree[x].r = r;
    tree[x].cover = tree[x].len = 0;
    if (l<r) {
        int m = (l+r)>>1;
        build(ls,l,m);
        build(rs,m+1,r);
    }
}
void update(int x, int l, int r, int val)
{
    int L = tree[x].l, R = tree[x].r;
    if (l <= L && R <= r) {
        tree[x].cover += val;
    } else {
        int m = (L+R)>>1;
        if (l<=m) update(ls,l,r,val);
        if (m<r)  update(rs,l,r,val);
    }
    push_up(x);
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int n, kase = 0;
    double x1,x2,y1,y2;
    while (~scanf("%d", &n) && n) {
        Y.clear();
        REP(i,n) {
            scanf("%lf%lf%lf%lf", &x1,&y1,&x2,&y2);
            line[i<<1] = (Line){x1,y1,y2,1};
            line[i<<1|1] = (Line){x2,y1,y2,-1};
            Y.pb(y1), Y.pb(y2);
        }
        n <<= 1;
        sort(line,line+n);
        sort(ALL(Y)); Y.erase(unique(ALL(Y)),Y.end());
        build(1,1,SZ(Y));
        double ans = 0;
        REP(i,n-1) {
            int l = ID(line[i].y1)+1, r = ID(line[i].y2);
            update(1,l,r,line[i].sign);
            ans += tree[1].len*(line[i+1].x-line[i].x);
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n", ++kase, ans);
    }

    return 0;
}












































































