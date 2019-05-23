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
const int MAXN = 1e4+5, MAXM = 5e3+5, INF = 0x3f3f3f3f, MOD = 10007;

int n,m,K,a[111][MAXN],b[111][MAXN],d[111][MAXN],Sa[MAXN],Sb[MAXN],Q[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d%d", &n,&m,&K)==3 && n) {
        n++;
        FOR(i,1,n)FOR(j,1,m) scanf("%d", &a[i][j]);
        FOR(i,1,n)FOR(j,1,m) scanf("%d", &b[i][j]);
        FOR(i,1,n) {
            FOR(j,1,m) Sa[j]=Sa[j-1]+a[i][j], Sb[j]=Sb[j-1]+b[i][j];
            int st=1, ed=0;
            FOR(j,0,m) {
                while (st<=ed && Sb[j]-Sb[Q[st]]>K) st++;
                while (st<=ed && Sa[j]-d[i-1][j]<=Sa[Q[ed]]-d[i-1][Q[ed]]) ed--;
                Q[++ed]=j;
                int mi=Q[st];
                d[i][j]=Sa[j]-Sa[mi]+d[i-1][mi];
            }
            Sa[m]=Sb[m]=0;
            ROF(j,1,m) Sa[j-1]=Sa[j]+a[i][j], Sb[j-1]=Sb[j]+b[i][j];
            st=1, ed=0;
            ROF(j,0,m) {
                while (st<=ed && Sb[j]-Sb[Q[st]]>K) st++;
                while (st<=ed && Sa[j]-d[i-1][j]<=Sa[Q[ed]]-d[i-1][Q[ed]]) ed--;
                Q[++ed]=j;
                int mi=Q[st];
                d[i][j]=max(d[i][j], Sa[j]-Sa[mi]+d[i-1][mi]);
            }
        }
        int ans=d[n][0];
        FOR(j,1,m) ans=max(ans, d[n][j]);
        printf("%d\n", ans);
    }

    return 0;
}






































