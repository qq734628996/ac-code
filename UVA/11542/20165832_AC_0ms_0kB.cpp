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
const int MAXN = 1e3+9, MAXM = 1e4+5;

const int maxn=505;
int vis[maxn],prime[maxn],tot;
void getPrime(int n)
{
    FOR(i,2,n) {
        if (!vis[i]) prime[tot++]=i;
        REP(j,tot) {
            if (i*prime[j]>n) break;
            vis[i*prime[j]]=1;
            if (i%prime[j]==0) break;
        }
    }
}
typedef int Matrix[maxn][maxn];
int Rank(Matrix A, int m, int n)
{
    int i=0,j=0;
    while (i<m && j<n) {
        int r=i;
        FOR(k,i,m-1) if (A[k][j]) { r=k; break; }
        if (A[r][j]) {
            if (r!=i) FOR(k,0,n) swap(A[r][k], A[i][k]);
            FOR(u,i+1,m-1) if (A[u][j]) FOR(k,i,n) A[u][k]^=A[i][k];
            i++;
        }
        j++;
    }
    return i;
}
Matrix A;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    getPrime(500);
    int T; scanf("%d", &T);
    while (T--) {
        memset(A,0,sizeof(A));
        int n, maxp=0;
        scanf("%d", &n);
        REP(i,n) {
            LL x; scanf("%lld", &x);
            REP(j,tot) while (x%prime[j]==0) {
                maxp=max(maxp,j);
                x/=prime[j];
                A[j][i]^=1;
            }
        }
        int r=Rank(A,maxp+1,n);
        printf("%lld\n", (1LL<<(n-r))-1);
    }

    return 0;
}




































