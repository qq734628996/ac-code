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

int C,n,x[MAXN],y[MAXN],w[MAXN];
int dis[MAXN],dis2o[MAXN],d[MAXN],q[MAXN];
int f(int i) { return d[i]-dis[i+1]+dis2o[i+1]; }

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &C,&n);
        FOR(i,1,n) {
            scanf("%d%d%d", &x[i],&y[i],&w[i]);
            w[i]+=w[i-1];
            dis2o[i]=abs(x[i])+abs(y[i]);
            dis[i]=dis[i-1]+abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
        }
        int st=0,ed=1;
        FOR(i,1,n) {
            while (st<ed && w[i]-w[q[st]]>C) st++;
            d[i]=f(q[st])+dis[i]+dis2o[i];
            while (st<ed && f(i)<=f(q[ed-1])) ed--;
            q[ed++]=i;
        }
        printf("%d\n", d[n]);
        if (T) puts("");
    }

    return 0;
}










































