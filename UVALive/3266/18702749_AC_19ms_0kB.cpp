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

int n,a[MAXN],b[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n)==1 && n) {
        REP(i,n) scanf("%d", &a[i]);
        REP(i,n) scanf("%d", &b[i]);
        sort(a,a+n);
        sort(b,b+n);
        int al=0, ar=n-1, bl=0, br=n-1, ans=0;
        REP(i,n) {
            if (a[al]>b[bl]) al++, bl++, ans++;
            else if (a[ar]>b[br]) ar--, br--, ans++;
            else if (a[al]==b[br]) al++, br--;
            else al++, br--, ans--;
        }
        printf("%d\n", ans*200);
    }

    return 0;
}









































