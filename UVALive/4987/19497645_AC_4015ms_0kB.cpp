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
const int MAXN = 4e3+5, MAXM = 5e3+5, INF = 0x3f3f3f3f, MOD = 10007;

struct node {
    int id,x,ans;
} a[MAXN],b[MAXN];
bool cmp1(node& x, node& y) { return x.x<y.x; }
bool cmp2(node& x, node& y) { return x.id<y.id; }
int n,m,pre[MAXN][MAXN];
LL d[MAXN][MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n)==1) {
        FOR(i,1,n) scanf("%d", &a[i].x), a[i].id=i;
        scanf("%d", &m);
        FOR(i,1,m) scanf("%d", &b[i].x), b[i].id=i;
        sort(a+1,a+1+n,cmp1);
        sort(b+1,b+1+m,cmp1);
        memset(d,INF,sizeof(d));
        d[1][1]=abs(a[1].x-b[1].x);
        FOR(i,2,n)FOR(j,1,m) {
            if (1<j && d[i-1][j-1]<d[i-1][j]) d[i][j]=d[i-1][j-1], pre[i][j]=j-1;
            else d[i][j]=d[i-1][j], pre[i][j]=j;
            d[i][j]+=abs(a[i].x-b[j].x);
        }
        printf("%lld\n", d[n][m]);
        for (int i=n,j=m; i>0; j=pre[i][j],i--) {
            a[i].ans=b[j].id;
        }
        sort(a+1,a+1+n,cmp2);
        FOR(i,1,n) printf("%d%c", a[i].ans,i==n?'\n':' ');
    }

    return 0;
}





































