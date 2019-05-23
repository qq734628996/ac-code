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
const int MAXN = 2e5+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

typedef pair<double,int> pdi;
pii e[MAXN];
//0<x+at<w
void upd(int x, int a, int w, int& L, int& R)
{
    if (!a) {
        if (x<=0 || x>=w) R=L-1;
    } else if (a>0) {
        L=max(L,-2520*x/a);
        R=min(R,2520*(w-x)/a);
    } else {
        L=max(L,2520*(w-x)/a);
        R=min(R,-2520*x/a);
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        int w,h,n,tot=0;
        scanf("%d%d%d", &w,&h,&n);
        REP(i,n) {
            int x,y,a,b,L=0,R=INF;
            scanf("%d%d%d%d", &x,&y,&a,&b);
            upd(x,a,w,L,R);
            upd(y,b,h,L,R);
            if (R>L) {
                e[tot++]=pii(L,1);
                e[tot++]=pii(R,0);
            }
        }
        sort(e,e+tot);
        int cnt=0,ans=0;
        REP(i,tot) {
            if (e[i].se) ans=max(ans,++cnt);
            else cnt--;
        }
        printf("%d\n", ans);
    }

    return 0;
}










































