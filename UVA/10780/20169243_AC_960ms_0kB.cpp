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
const int INF = 0x3f3f3f3f, MOD = 1000000;
const double eps = 1e-14;
const int MAXN = 1e4+9, MAXM = 1e4+5;

int vis[MAXN],prime[MAXN],tot;
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
int e1[MAXN],e2[MAXN],kase;
void add(int* e, int x)
{
    REP(i,tot) {
        while (x%prime[i]==0) {
            x/=prime[i];
            e[i]++;
        }
        if (x==1) break;
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    getPrime(10000);
    int T; scanf("%d", &T);
    while (T--) {
        int m,n; scanf("%d%d", &m,&n);
        memset(e1,0,sizeof(e1));
        memset(e2,0,sizeof(e2));
        add(e1,m);
        FOR(i,2,n) add(e2,i);
        int ans=INF;
        REP(i,tot)if (e1[i]) {
            if (e1[i]>e2[i]) {
                ans=-1;
                break;
            }
            ans=min(ans,e2[i]/e1[i]);
        }
        if (ans==INF) ans=1;
        printf("Case %d:\n", ++kase);
        if (ans==-1) puts("Impossible to divide");
        else printf("%d\n", ans);
    }

    return 0;
}




































