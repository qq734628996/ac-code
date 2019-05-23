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
const int MAXN = 1e5+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n,S[123],d[123][123],vis[123][123],kase;
int dp(int i, int j)
{
    int& ans=d[i][j];
    if (vis[i][j]==kase) return ans;
    vis[i][j]=kase;
    ans=0;
    FOR(x,i+1,j) ans=min(ans,dp(x,j));
    ROF(x,i,j-1) ans=min(ans,dp(i,x));
    return ans=S[j]-S[i-1]-ans;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n)==1 && n) {
        kase++;
        FOR(i,1,n) scanf("%d", &S[i]), S[i]+=S[i-1];
        printf("%d\n", 2*dp(1,n)-S[n]);
    }

    return 0;
}










































