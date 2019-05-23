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
pdi e[MAXN];
//0<x+at<w
void upd(int x, int a, int w, double& L, double& R)
{
    if (!a) {
        if (x<=0 || x>=w) R=L-1;
    } else if (a>0) {
        L=max(L,-(double)x/a);
        R=min(R,(double)(w-x)/a);
    } else {
        L=max(L,(double)(w-x)/a);
        R=min(R,-(double)x/a);
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
            int x,y,a,b;
            scanf("%d%d%d%d", &x,&y,&a,&b);
            double L=0,R=1e9;
            upd(x,a,w,L,R);
            upd(y,b,h,L,R);
            if (R>L) {
                e[tot++]=pdi(L,1);
                e[tot++]=pdi(R,0);
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










































