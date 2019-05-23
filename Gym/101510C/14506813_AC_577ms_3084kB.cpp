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
const int MAXN  = 2e5+10, INF = ~0U>>1, MOD = ~0U>>1;

LL a[MAXN], n, k, ans;
typedef pair<LL, int> pli;
priority_queue<pli> pq;

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    cin >> n >> k;
    FOR(i,1,n) cin >> a[i];
    sort(a+1, a+n+1);
    int st = 1;
    ans = max(a[st+k-1] - a[st], a[n] - a[n-k+1]);
    FOR(i,1,n-k) {
        if (a[i+k-1] - a[i] <= ans) {
            st = i;
        } else {
            pq.push(pli(-(a[i+k-1] - a[i]), i));
        }
        if (st+k-1 < i) {
            pq.push(pii(-(a[i+k-1] - a[i]), i));
            while (!pq.empty()) {
                pli tmp = pq.top(); pq.pop();
                if (tmp.second+k-1 >= i) {
                    st = tmp.second;
                    ans = max(ans, -tmp.first);
                    break;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}

















































































