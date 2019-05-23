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

int a[55][55],m,n,q,kase;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (cin>>m>>n && m+n) {
        if (kase++) puts("");
        printf("Spreadsheet #%d\n", kase);
        FOR(i,1,m)FOR(j,1,n) a[i][j]=i*n+j;
        int n_bak=n;
        cin>>q;
        REP(i,q) {
            string op; cin>>op;
            if (op=="EX") {
                int r1,c1,r2,c2;
                cin>>r1>>c1>>r2>>c2;
                swap(a[r1][c1],a[r2][c2]);
                continue;
            }
            int x; cin>>x;
            vector<int> V;
            REP(j,x) {
                int y; cin>>y;
                V.pb(y);
            }
            sort(ALL(V),greater<int>());
            if (op=="DR") {
                for (auto& r:V) {
                    m--;
                    FOR(i,r,m)FOR(j,1,n) a[i][j]=a[i+1][j];
                }
            } else if (op=="DC") {
                for (auto& c:V) {
                    n--;
                    FOR(i,1,m)FOR(j,c,n) a[i][j]=a[i][j+1];
                }
            } else if (op=="IR") {
                for (auto& r:V) {
                    m++;
                    ROF(i,r,m)FOR(j,1,n) a[i][j]=a[i-1][j];
                    FOR(j,1,n) a[r][j]=-1;
                }
            } else if (op=="IC") {
                for (auto& c:V) {
                    n++;
                    FOR(i,1,m)ROF(j,c,n) a[i][j]=a[i][j-1];
                    FOR(i,1,m) a[i][c]=-1;
                }
            }
        }
        cin>>q;
        REP(i,q) {
            int r,c; cin>>r>>c;
            bool fail=true;
            FOR(i,1,m)FOR(j,1,n) if (a[i][j]==r*n_bak+c) {
                printf("Cell data in (%d,%d) moved to (%d,%d)\n", r,c,i,j);
                fail=false;
            }
            if (fail) printf("Cell data in (%d,%d) GONE\n", r,c);
        }
    }

    return 0;
}













































