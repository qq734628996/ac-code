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
const int MAXN = 5e4+5, MAXM = 5e3+5, INF = 0x3f3f3f3f, MOD = 10007;

const LL inf=(1LL<<62)+1;
int p[16]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
LL ans;
int op,n,d[MAXN];
void init()
{
    int m=MAXN-5;
    FOR(i,1,m) d[i]=i;
    FOR(i,1,m) {
        for (int j=i; j<=m; j+=i) d[j]--;
        if (!d[d[i]]) d[d[i]]=i;
        d[i]=0;
    }
}
void dfs(int dep, LL now, int num, int up)
{
    if (num>n) return;
    if (num==n && ans>now) { ans=now; return; }
    FOR(i,1,up) {
        if (ans/p[dep]<now || num*(i+1)>n) break;
        now*=p[dep];
        if (n%(num*(i+1))==0) dfs(dep+1,now,num*(i+1),i);
    }
}

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    init();
    int T; scanf("%d", &T);
    FOR(kase,1,T) {
        scanf("%d%d", &op,&n);
        if (op) ans=d[n];
        else { ans=inf; dfs(0,1,1,62); }
        printf("Case %d: ", kase);
        if (!ans) puts("Illegal");
        else if (ans>=inf) puts("INF");
        else printf("%lld\n", ans);
    }

    return 0;
}





































