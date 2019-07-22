#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n) printf("%d%c", A[i],i==n-1?'\n':' '); }
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
const int MAXN = 3e5+9, MAXM = 3e3+9;

int n,a[MAXN],b[MAXN],r[MAXN],is[MAXN];
bool cmp(const int i, const int j)
{
    return a[i]<a[j];
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n)==1) {
        memset(is,0,sizeof(is));
        REP(i,2*n+1) scanf("%d%d", &a[i],&b[i]), r[i]=i;
        sort(r,r+2*n+1,cmp);
        for (int i=0; i<2*n; i+=2) {
            int x=r[i];
            int y=r[i+1];
            if (b[x]>b[y]) is[x]=1;
            else is[y]=1;
        }
        is[r[2*n]]=1;
        REP(i,2*n+1)if (is[i]) printf("%d\n", i+1);
    }

    return 0;
}


































