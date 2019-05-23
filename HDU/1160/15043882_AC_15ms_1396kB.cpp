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
const int MAXN = 1e3+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n, nxt[MAXN], dp[MAXN];
struct node {
    int x, y, id;
    bool operator<(const node& o) const { return x < o.x; }
} a[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d%d", &a[n].x, &a[n].y)) n++;
    REP(i,n) a[i].id = i+1;
    sort(a, a+n);
    int st = n-1;
    PER(i,n) {
        dp[i] = 1;
        int j = i+1;
        for (; j < n; j++) {
            if (a[i].x < a[j].x && a[i].y > a[j].y && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                nxt[i] = j;
            }
        }
        if (dp[i] == 1) nxt[i] = n;
        if (dp[i] >= dp[st]) st = i;
    }
    printf("%d\n", dp[st]);
    for (int i = st; i < n; i = nxt[i])
        printf("%d\n", a[i].id);

    return 0;
}




















































































