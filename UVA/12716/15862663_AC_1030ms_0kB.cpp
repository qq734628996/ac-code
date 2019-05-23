#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
#define TR(e,x) for(auto e = x.begin(); e != x.end(); e++)
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
const int MAXN = 3e7+5, MAXM = 1e2+5, INF = 0x3f3f3f3f, MOD = 1e4+1;

int a[MAXN], ans[MAXN], T, n, kase;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    for (int i = 1; i < MAXN; i++) {
        for (int j = i*2; j < MAXN; j += i) {
            if (j-i == (j^i)) a[j]++;
        }
    }
    for (int i = 2; i < MAXN; i++) ans[i] = ans[i-1]+a[i];
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("Case %d: %d\n", ++kase, ans[n]);
    }

    return 0;
}














































































