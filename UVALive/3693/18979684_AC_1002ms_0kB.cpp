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
const int MAXN = 1e6+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int b[16],a[1820][24],id[1<<16],kase;
void init()
{
    memset(id,-1,sizeof(id));
    int cnt=0;
    for (int i=0x0f; i<(1<<16); ) {
        id[i]=cnt++;
        int t=i&-i;
        i=(i+t)|(((i^(i+t))>>2)/t);
    }
}
bool read()
{
    if (scanf("%d", &b[0])!=1 || !b[0]) return false;
    FOR(i,1,15) scanf("%d", &b[i]);
    return true;
}
LL cal(int x)
{
    static int vis[1<<15];
    LL sum=0;
    for (int i=x; i; i=(i-1)&x) if (~id[i]) {
        REP(j,24) vis[a[id[x^i]][j]]=0;
        REP(j,24) vis[a[id[i]][j]]++;
        REP(j,24) sum+=vis[a[id[x^i]][j]];
    }
    return sum;
}
LL solve()
{
    for (int i=0x0f; i<(1<<16); ) {
        int tmp[4], cnt=0, k=id[i];
        REP(j,16) if (i>>j&1) {
            tmp[cnt++]=b[j];
        }
        cnt=0;
        int p[4]={0,1,2,3};
        do {
            a[k][cnt]=0;
            REP(j,4) a[k][cnt]+=tmp[p[j]]*(j+1);
            cnt++;
        } while (next_permutation(p,p+4));
        int t=i&-i;
        i=(i+t)|(((i^(i+t))>>2)/t);
    }
    LL ans=0;
    for (int i=0xff, j=0; i<(1<<16) && j<6435; j++) {
        ans+=cal(i)*cal(0xffff^i);
        int t=i&-i;
        i=(i+t)|(((i^(i+t))>>2)/t);
    }
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    init();
    while (read()) {
        printf("Case %d: %lld\n", ++kase,solve()/4);
    }

    return 0;
}









































