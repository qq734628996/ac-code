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
const int MAXN = 1e3+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;



int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int m,n,kase=0;
    while (scanf("%d%d", &m,&n)==2 && m) {
        printf("Region %d\n", ++kase);
        n*=m;
        map<int,int> mp;
        REP(i,n) {
            int x; scanf("%d", &x);
            mp[x]++;
        }
        double tot; scanf("%lf", &tot);
        tot/=100;
        double lo=mp.begin()->fi;
        int cnt=0;
        while (true) {
            if (tot<1e-6) {
                printf("Water level is %.2f meters.\n", lo);
                printf("%.2f percent of the region is under water.\n", 100.0*cnt/n);
                break;
            }
            cnt+=mp.begin()->se;
            mp.erase(mp.begin());
            double hi=INF;
            if (SZ(mp)) hi=mp.begin()->fi;
            if (tot<(hi-lo)*cnt) {
                lo+=tot/cnt;
                tot=0;
            } else {
                tot-=(hi-lo)*cnt;
                lo=hi;
            }
        }
        puts("");
    }

    return 0;
}












































