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
const int MAXN = 1e2+5, MAXM = 5e3+5, INF = 0x3f3f3f3f, MOD = 10007;

int n,V,a[22][22],b[22][22];
LL f[22][22][500],g[22][22][500];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d", &n,&V)==2 && n) {
        ROF(i,1,n)FOR(j,1,i) scanf("%d", &a[i][j]);
        b[1][1]=a[1][1];
        FOR(i,2,n)FOR(j,1,i) scanf("%d", &b[i][j]);
        FOR(i,1,n)FOR(j,1,i)FOR(k,0,V) f[i][j][k]=g[i][j][k]=0;
        FOR(j,1,n) g[n][j][b[n][j]]=1;
        ROF(i,1,n-1)FOR(j,1,i) {
            int C=b[i][j];
            FOR(k,C,V) g[i][j][k]+=g[i+1][j][k-C]+g[i+1][j+1][k-C];
        }
        FOR(k,0,V) f[1][1][k]=g[1][1][k];
        FOR(i,2,n)FOR(j,1,i) {
            int C=a[i][j];
            if (j>1) {
                FOR(k,C,V) f[i][j][k]+=f[i-1][j-1][k-C];
            }
            if (j<i) {
                FOR(k,C,V) f[i][j][k]+=f[i-1][j][k-C];
            }
        }
        LL ans=0;
        FOR(j,1,n) ans+=f[n][j][V];
        printf("%lld\n", ans);
        if (ans) {
            int nj, w;
            FOR(j,1,n) if (f[n][j][V]) {
                printf("%d ", j-1);
                nj=j, w=V;
                ROF(i,1,n-1) {
                    int C=a[i+1][nj];
                    if (nj>1 && f[i][nj-1][w-C]) {
                        putchar('L');
                        nj--;
                    } else {
                        putchar('R');
                    }
                    w-=C;
                }
                break;
            }
            FOR(i,2,n) {
                int C=b[i-1][nj];
                if (g[i][nj][w-C]) {
                    putchar('L');
                } else {
                    putchar('R');
                    nj++;
                }
                w-=C;
            }
        }
        puts("");
    }

    return 0;
}






































