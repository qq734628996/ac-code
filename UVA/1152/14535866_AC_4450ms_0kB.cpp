#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define TR(e,x) for(auto e = x.begin(); e != x.end(); e++)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n-1) printf("%d ", A[i]); printf("%d\n", A[n-1]); }
#define SHOW2(A,m,n) { REP(i,m) { REP(j,n-1) printf("%d ", A[i][j]); printf("%d\n", A[i][n-1]); } }
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)((x).size())
typedef long long LL;
typedef pair<int, int> pii;
const int MAXN  = 4e3+5, INF = ~0U>>1, MOD = ~0U>>1;

int T, n, kase;
LL a[MAXN][4];
unordered_map<LL, int> mp;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        if (kase++) puts("");
        scanf("%d", &n);
        REP(i,n)REP(j,4) scanf("%lld", &a[i][j]);
        mp.clear();
        REP(i,n)REP(j,n) {
            LL x = a[i][0]+a[j][1];
            if (mp.count(x)) mp[x]++;
            else mp[x] = 1;
        }
        int ans = 0;
        REP(i,n)REP(j,n) {
            LL x = -a[i][2]-a[j][3];
            if (mp.count(x)) ans += mp[x];
        }
        printf("%d\n", ans);
    }

    return 0;
}












































































