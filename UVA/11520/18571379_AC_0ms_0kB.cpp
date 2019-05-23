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
const int MAXN = 1e4+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n;
char a[22][22];
const int r[]={0,1,0,-1};
const int c[]={1,0,-1,0};
#define vld(i,j) (0<=i&&i<n&&0<=j&&j<n)
bool jdg(int i, int j, int ch)
{
    REP(k,4) {
        int x=i+r[k], y=j+c[k];
        if (vld(x,y) && a[x][y]==ch) return false;
    }
    return true;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    FOR(kase,1,T) {
        printf("Case %d:\n", kase);
        scanf("%d", &n);
        REP(i,n) scanf("%s", a[i]);
        REP(i,n)REP(j,n) if (a[i][j]=='.') {
            FOR(k,'A','Z') if (jdg(i,j,k)) {
                a[i][j]=k;
                break;
            }
        }
        REP(i,n) puts(a[i]);
    }

    return 0;
}










































