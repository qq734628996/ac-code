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
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const int INF = 0x3f3f3f3f, MOD = 1000000007;
const double PI = acos(-1), EPS = 1e-15;
const int MAXN = 1e3+9, MAXM = 3e3+9;



int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int n,m;
    while (scanf("%d%d", &n,&m)==2) {
        map<pii,int> Sx,Sy;
        REP(i,n) {
            int x,y; scanf("%d%d", &x,&y);
            Sx[{x,y}]++;
            Sy[{y,x}]++;
        }
        REP(i,m) {
            int x,y,z; scanf("%d%d%d", &x,&y,&z);
            while (true) {
                auto it=Sx.lower_bound({x,y-z});
                if (it==Sx.end()) break;
                pii now=it->fi;
                int xx=now.fi, yy=now.se;
                if (xx!=x || yy>y+z) break;
                Sx.erase({xx,yy});
                Sy.erase({yy,xx});
            }
            while (true) {
                auto it=Sy.lower_bound({y,x-z});
                if (it==Sy.end()) break;
                pii now=it->fi;
                int xx=now.se, yy=now.fi;
                if (yy!=y || xx>x+z) break;
                Sx.erase({xx,yy});
                Sy.erase({yy,xx});
            }
        }
        int res=0;
        for (auto& i:Sx) res+=i.se;
        printf("%d\n", n-res);
    }

    return 0;
}
































