#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
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
const int MAXN = 1e6+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

struct node {
    double x,y;
    bool operator<(const node& o) const {
        if (x!=o.x) return x<o.x;
        return y>o.y;
    }
};
vector<node> V;
int n;
double L,W;
int solve()
{
    sort(ALL(V));
    if (V.empty() || V[0].x>1e-7) return -1;
    int cnt=1;
    double pre,nxt;
    pre=nxt=V[0].y;
    if (pre==L) return 1;
    FOR(i,1,SZ(V)-1) {
        double l=V[i].x,r=V[i].y;
        if (l>nxt) return -1;
        if (l>pre) {
            cnt++;
            pre=nxt;
        }
        nxt=max(nxt,r);
        if (nxt==L) return cnt+1;
    }
    return -1;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%lf%lf", &n,&L,&W)==3) {
        W/=2;
        V.clear();
        REP(i,n) {
            double x,r; scanf("%lf%lf", &x,&r);
            if (r>W) {
                double dx=sqrt(r*r-W*W);
                if (0<x+dx || x-dx<L) {
                    V.pb(node{max(0.0,x-dx),min(L,x+dx)});
                }
            }
        }
        printf("%d\n", solve());
    }

    return 0;
}










































