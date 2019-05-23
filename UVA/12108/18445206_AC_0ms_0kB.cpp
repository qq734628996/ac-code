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

int n,a[11],b[11],c[11],d[11],kase;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n)==1 && n) {
        printf("Case %d: ", ++kase);
        REP(i,n) scanf("%d%d%d", &a[i],&b[i],&c[i]);
        memcpy(d,c,sizeof(c));
        int clk=0,cnt=0;
        REP(i,n) cnt+=d[i]>a[i];
        while (true) {
            clk++;
            if (!cnt) {
                printf("%d\n", clk);
                break;
            }
            bool flag=2*cnt>n;
            REP(i,n) {
                d[i]++;
                if (d[i]>a[i]+b[i]) {
                    d[i]=1;
                    cnt--;
                } else if (d[i]==a[i]+1) {
                    if (flag) cnt++;
                    else d[i]=1;
                }
            }
            if (memcmp(c,d,sizeof(c))==0) {
                puts("-1");
                break;
            }
        }
    }

    return 0;
}












































