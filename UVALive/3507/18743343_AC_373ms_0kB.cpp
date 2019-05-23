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
const int MAXN = 1e6+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n;
pii a[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        REP(i,n) scanf("%d%d", &a[i].se,&a[i].fi);
        sort(a,a+n);
        int now=0;
        priority_queue<int> pq;
        REP(i,n) {
            int d=a[i].fi, t=a[i].se;
            if (now+t<=d) {
                pq.push(t);
                now+=t;
            } else if (SZ(pq) && t<pq.top()) {
                now+=t-pq.top();
                pq.pop();
                pq.push(t);
            }
        }
        printf("%d\n", SZ(pq));
        if (T) puts("");
    }

    return 0;
}









































