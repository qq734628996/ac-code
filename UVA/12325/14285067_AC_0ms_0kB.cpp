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
const int MAXN  = 5e4, INF = ~0U>>1, MOD = ~0U>>1;

int T, N, s1, v1, s2, v2, kase;
LL calc(int s1, int v1, int s2, int v2, int cnt)
{
    LL ans = 0;
    FOR(i,0,cnt) {
        int j = (N-s1*i)/s2;
        ans = max(ans, (LL)v1*i + (LL)v2*j);
    }
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d%d", &N, &s1, &v1, &s2, &v2);
        LL ans = 0;
        if (N/s1 <= MAXN) ans = calc(s1, v1, s2, v2, N/s1);
        else if (N/s2 <= MAXN) ans = calc(s2, v2, s1, v1, N/s2);
        else {
            if ((LL)s2*v1 < (LL)s1*v2) ans = calc(s1, v1, s2, v2, s2-1);
            else ans = calc(s2, v2, s1, v1, s1-1);
        }
        printf("Case #%d: %lld\n", ++kase, ans);
    }

    return 0;
}
















































































