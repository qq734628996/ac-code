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

const char* r="ACGT";
int m,n;
char a[55][1111],ans[1111];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &m,&n);
        REP(i,m) scanf("%s", a[i]);
        REP(j,n) {
            int cnt[4]={0};
            REP(i,m) cnt[strchr(r,a[i][j])-r]++;
            int ma=cnt[0];
            REP(i,4) ma=max(ma,cnt[i]);
            REP(i,4) if (cnt[i]==ma) {
                ans[j]=r[i];
                break;
            }
        }
        ans[n]='\0';
        int tot=0;
        REP(i,m)REP(j,n) tot+=ans[j]!=a[i][j];
        printf("%s\n%d\n", ans,tot);
    }

    return 0;
}













































