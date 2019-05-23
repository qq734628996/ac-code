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

int a,b,c[11],d[11][MAXN],ma;
int dp(int pos, int sum, bool limit)
{
    if (sum<0) return 0;
    if (pos==-1) return 1;
    if (!limit && ~d[pos][sum]) return d[pos][sum];
    int ans=0;
    int up=limit?c[pos]:9;
    FOR(i,0,up) {
        ans+=dp(pos-1,sum-i*(1<<pos),limit&&i==up);
    }
    if (!limit) d[pos][sum]=ans;
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    memset(d,-1,sizeof(d));
    int T; scanf("%d", &T);
    FOR(i,1,T) {
        scanf("%d%d", &a,&b);
        ma=0;
        for (int j=0; a; j++) {
            ma+=(a%10)*(1<<j);
            a/=10;
        }
        int cnt=0;
        while (b) {
            c[cnt++]=b%10;
            b/=10;
        }
        printf("Case #%d: %d\n", i,dp(cnt-1,ma,true));
    }

    return 0;
}

//0,1,2,3,4,5,10,11,12,13,20,21,100







































