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
const int MAXN = 1e3+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

LL a[MAXN];
void showip(LL x)
{
    PER(i,4) {
        if (i<3) putchar('.');
        printf("%lld", (x>>(i*8))&((1<<8)-1));
    }
    puts("");
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int n;
    while (~scanf("%d", &n)) {
        memset(a,0,sizeof(a));
        REP(i,n)REP(j,4) {
            int x; scanf("%d", &x); getchar();
            a[i]=(a[i]<<8)+x;
        }
        sort(a,a+n);
        int i;
        for (i=0; ; i++) if (!((a[0]^a[n-1])>>i)) break;
        showip(a[0]&((LL)~0U>>i<<i));
        showip((LL)~0U>>i<<i);
    }

    return 0;
}












































