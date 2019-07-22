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

int m,n,a[MAXN][MAXN];
char s[MAXN][MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d", &m,&n)==2) {
        memset(a,0,sizeof(a));
        REP(i,m) scanf("%s", s[i]);
        REP(i,m) {
            bool flag=false;
            REP(j,n) {
                if (s[i][j]=='B') flag=true;
                else if (flag==true) a[i][j]++;
            }
            flag=false;
            PER(j,n) {
                if (s[i][j]=='B') flag=true;
                else if (flag==true) a[i][j]++;
            }
        }
        REP(j,n) {
            bool flag=false;
            REP(i,m) {
                if (s[i][j]=='B') flag=true;
                else if (flag==true) a[i][j]++;
            }
            flag=false;
            PER(i,m) {
                if (s[i][j]=='B') flag=true;
                else if (flag==true) a[i][j]++;
            }
        }
        REP(i,m){
            REP(j,n) {
                if (s[i][j]=='B') putchar('B');
                else putchar(a[i][j]+'0');
            }
            puts("");
        }
    }

    return 0;
}

































