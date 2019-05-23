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
const int MAXN = 1e2+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n,W,H,ansX,ansY,ansL;
pii a[MAXN];
void upd(int x, int y, int l)
{
    if (l>ansL) {
        ansX=x;
        ansY=y;
        ansL=l;
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
        scanf("%d%d%d", &n,&W,&H);
        REP(i,n) scanf("%d%d", &a[i].fi,&a[i].se);
        ansL=0;

        sort(a,a+n,[](pii& x, pii& y){
             return x.se<y.se;
        });
        int last=0;
        REP(i,n) upd(0,last,min(W,a[i].se-last)), last=a[i].se;
        upd(0,last,min(W,H-last));

        a[n++]=pii(0,0);
        a[n++]=pii(W,0);
        sort(a,a+n);
        n=unique(a,a+n)-a;
        REP(i,n) {
            int x=a[i].fi, y=a[i].se;
            int up=0, down=H;
            int j=i+1;
            while (j<n && a[j].fi==x) j++;
            while (j<n) {
                int nx=a[j].fi;
                upd(x,up,min(down-up,nx-x));
                do {
                    if (a[j].se==y) {
                        j=n;
                        break;
                    }
                    if (a[j].se<y) up=max(up,a[j].se);
                    else down=min(down,a[j].se);
                    j++;
                } while (j<n && a[j].fi==nx);
            }
        }
        PER(i,n) {
            int x=a[i].fi, y=a[i].se;
            int up=0, down=H;
            int j=i-1;
            while (0<=j && a[j].fi==x) j--;
            while (0<=j) {
                int nx=a[j].fi;
                upd(nx,up,min(down-up,x-nx));
                do {
                    if (a[j].se==y) {
                        j=-1;
                        break;
                    }
                    if (a[j].se<y) up=max(up,a[j].se);
                    else down=min(down,a[j].se);
                    j--;
                } while (0<=j && a[j].fi==nx);
            }
        }

        printf("%d %d %d\n", ansX,ansY,ansL);
        if (T) puts("");
    }

    return 0;
}









































