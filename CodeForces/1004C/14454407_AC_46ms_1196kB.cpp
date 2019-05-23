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
const int MAXN  = 1e5+5, INF = ~0U>>1, MOD = ~0U>>1;

int a[MAXN], lvis[MAXN], rvis[MAXN], cnt, n;
LL ans;

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &n);
    REP(i,n) scanf("%d", &a[i]);
    REP(i,n) rvis[a[i]]++;
    REP(j,n) {
        int i = a[j];
        if (rvis[i] == 1) {
            ans += cnt;
        }
        if (!lvis[i]) cnt++;
        lvis[i]++;
        rvis[i]--;
    }
    cout << ans << endl;

    return 0;
}















































































