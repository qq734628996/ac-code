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

int n,a[105];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n)==1, n) {
        memset(a,0,sizeof(a));
        REP(i,n) {
            int x; scanf("%d", &x);
            a[x]++;
        }
        int j;
        for (j=100; j>0; j--) {
            if (a[j]) {
                a[j]--;
                break;
            }
        }
        FOR(i,1,100) while (a[i]) printf("%d ", i), a[i]--;
        printf("%d\n", j);
    }

    return 0;
}










































