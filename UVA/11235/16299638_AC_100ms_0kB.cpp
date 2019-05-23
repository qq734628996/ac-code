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
const int MAXN = 2e5+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 1000000007;

int n, q, a[MAXN], tot, l[MAXN], r[MAXN], d[MAXN][20];
void RMQ_init()
{
    FOR(i,1,tot) d[i][0] = a[i];
    for (int j = 1; (1<<j) <= tot; j++) {
        for (int i = 1; i+(1<<j)-1 <= tot; i++) {
            d[i][j] = max(d[i][j-1], d[i+(1<<(j-1))][j-1]);
        }
    }
}
int RMQ(int L, int R)
{
    int k = 0;
    while ((1<<(k+1)) <= R-L+1) k++;
    return max(d[L][k], d[R-(1<<k)+1][k]);
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d", &n, &q) == 2 && n) {
        int pre = INF;
        tot = 0;
        FOR(i,1,n) {
            int x; scanf("%d", &x);
            if (x != pre) {
                pre = x;
                tot++;
                l[tot] = r[tot] = i;
                a[tot] = 1;
            } else {
                r[tot] = i;
                a[tot]++;
            }
        }
        RMQ_init();
        while (q--) {
            int x, y; scanf("%d%d", &x, &y);
            int L = upper_bound(l+1, l+1+tot, x) - l;
            int R = lower_bound(r+1, r+1+tot, y) - r - 1;
            int t = 0;
            if (L <= R) t = RMQ(L, R);
            if (L-1 == R+1) printf("%d\n", y-x+1);
            else printf("%d\n", max(t, max(r[L-1]-x+1, y-l[R+1]+1)));
        }
    }

    return 0;
}












































































