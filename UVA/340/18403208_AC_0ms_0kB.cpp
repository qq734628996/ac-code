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

int kase,n,a[MAXN],b[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n)==1 && n) {
        printf("Game %d:\n", ++kase);
        REP(i,n) scanf("%d", &a[i]);
        while (true) {
            REP(i,n) scanf("%d", &b[i]);
            if (b[0]==0) break;
            int A=0,B=0;
            REP(i,n) A+=(a[i]==b[i]);
            FOR(i,1,9) {
                int cnt1=0,cnt2=0;
                REP(j,n) cnt1+=(i==a[j]);
                REP(j,n) cnt2+=(i==b[j]);
                B+=min(cnt1,cnt2);
            }
            printf("    (%d,%d)\n", A, B-A);
        }
    }

    return 0;
}














































