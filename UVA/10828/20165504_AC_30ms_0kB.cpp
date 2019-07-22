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
const int INF = 0x3f3f3f3f, MOD = 100000007;
const double eps = 1e-8;
const int MAXN = 1e2+9, MAXM = 1e4+5;

typedef double Matrix[MAXN][MAXN];
void gauss_jordan(Matrix A, int n)
{
    REP(i,n) {
        int r=i;
        FOR(j,i+1,n-1) if (fabs(A[j][i])>fabs(A[r][i])) r=j;
        if (fabs(A[r][i])<eps) continue;
        if (r!=i) FOR(j,0,n) swap(A[r][j], A[i][j]);
        REP(k,n) if (k!=i) ROF(j,i,n) A[k][j]-=A[k][i]/A[i][i]*A[i][j];
    }
}
Matrix A;
int n,d[MAXN],kase;
vector<int> pre[MAXN];
int inf[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n)==1 && n) {
        memset(d,0,sizeof(d));
        REP(i,n) pre[i].clear();
        int a,b;
        while (scanf("%d%d", &a,&b)==2 && a) {
            a--, b--;
            d[a]++;
            pre[b].pb(a);
        }
        memset(A,0,sizeof(A));
        REP(i,n) {
            A[i][i]=1;
            REP(j,SZ(pre[i])) A[i][pre[i][j]]-=1.0/d[pre[i][j]];
            if (i==0) A[i][n]=1;
        }
        gauss_jordan(A,n);
        memset(inf,0,sizeof(inf));
        PER(i,n) {
            if (fabs(A[i][i])<eps && fabs(A[i][n])>eps) inf[i]=1;
            FOR(j,i+1,n-1) if (fabs(A[i][j])>eps && inf[j]) inf[i]=1;
        }
        int q; scanf("%d", &q);
        printf("Case #%d:\n", ++kase);
        while (q--) {
            int u; scanf("%d", &u); u--;
            if (inf[u]) puts("infinity");
            else printf("%.3f\n", fabs(A[u][u])<eps ? 0 : A[u][n]/A[u][u]);
        }
    }

    return 0;
}




































