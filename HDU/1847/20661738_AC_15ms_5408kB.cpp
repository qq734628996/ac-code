#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n) cout<<A[i]<<(i==n-1?'\n':' '); }
#define SHOW2(A,m,n) { REP(j,m) SHOW1(A[j],n) }
#define pb push_back
#define fi first
#define se second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)((x).size())
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const int INF = 0x3f3f3f3f, MOD = 1000000007;
const double PI = acos(-1), EPS = 1e-15;
const int MAXN = 1e3+9, MAXM = 2e5+9;

int n,sg[MAXN],a[22];
int mex(int i)
{
    if (~sg[i]) return sg[i];
    int vis[MAXN];
    memset(vis,0,sizeof(vis));
    REP(j,11) {
        int k=i-a[j];
        if (k<0) break;
        vis[mex(k)]=1;
    }
    REP(j,MAXN) if (!vis[j]) { sg[i]=j; break; }
    return sg[i];
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    a[0]=1;
    FOR(i,1,10) a[i]=a[i-1]*2;
    memset(sg,-1,sizeof(sg));
    while (scanf("%d", &n)==1) {
        puts(mex(n)?"Kiki":"Cici");
    }

    return 0;
}



























