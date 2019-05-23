#include <bits/stdc++.h>
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
const int MAXN = 5e1+5, MAXM = 3e3+5, INF = 0x3f3f3f3f, MOD = 1e9+7;

int n, m, d[MAXN][MAXM], kase, maxi, f[MAXN][10];
const int c[10] = { 6,2,5,5,4,5,6,3,7,6 };
char ans[MAXN];

bool fillAns(int j, int i, int n, int res)
{
    if (j == i) return true;
    PER(k,10) if (d[i-j-1][(m+res-f[i-j][k])%m] + c[k] <= n) {
        ans[j] = '0'+k;
        if (fillAns(j+1, i, n-c[k], (m+res-f[i-j][k])%m)) return true;
    }
    return false;
}

void printAns()
{
    ROF(i,1,maxi) if (d[i][0] <= n) {
        REP(k,10) f[1][k] = k % m;
        FOR(j,2,i)REP(k,10) f[j][k] = (f[j-1][k] * 10) % m;
        fillAns(0,i,n,0);
        if (ans[0] == '0') puts("0");
        else ans[i] = '\0', puts(ans);
        return;
    }
    puts("-1");
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d", &n, &m), n) {
        printf("Case %d: ", ++kase);
        maxi = n/2;
        FOR(i,0,maxi)REP(j,m) d[i][j] = INF;
        d[0][0] = 0;
        REP(i,maxi)REP(j,m)REP(k,10) {
            int x = i+1, y = (j*10+k) % m;
            d[x][y] = min(d[x][y], d[i][j]+c[k]);
        }
        printAns();
    }

    return 0;
}


















































































