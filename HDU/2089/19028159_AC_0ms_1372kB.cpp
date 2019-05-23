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

int L,R,a[10],d[10][2];
int dp(int pos, bool if6, bool limit)
{
    if (pos==-1) return 1;
    if (!limit && ~d[pos][if6]) return d[pos][if6];
    int ans=0;
    int n=limit?a[pos]:9;
    FOR(i,0,n) {
        if (i==4) continue;
        if (if6 && i==2) continue;
        ans+=dp(pos-1,i==6,limit&&i==a[pos]);
    }
    if (!limit) d[pos][if6]=ans;
    return ans;
}
int solve(int x)
{
    int cnt=0;
    while (x) {
        a[cnt++]=x%10;
        x/=10;
    }
    return dp(cnt-1,false,true);
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    memset(d,-1,sizeof(d));
    while (scanf("%d%d", &L,&R)==2 && L&&R) {
        printf("%d\n", solve(R)-solve(L-1));
    }

    return 0;
}









































