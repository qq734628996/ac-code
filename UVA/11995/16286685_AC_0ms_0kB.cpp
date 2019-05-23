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
const int MAXN = 1e3+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 1000000007;



int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int n;
    while (~scanf("%d", &n)) {
        stack<int> S;
        queue<int> Q;
        priority_queue<int> pq;
        int ans[3];
        REP(i,3) ans[i] = 1;
        REP(i,n) {
            int x, y; scanf("%d%d", &x, &y);
            if (x == 1) {
                if (ans[0]) S.push(y);
                if (ans[1]) Q.push(y);
                if (ans[2]) pq.push(y);
            } else {
                if (ans[0]) {
                    if (!S.empty()) { ans[0] = S.top() == y; S.pop(); }
                    else ans[0] = 0;
                }
                if (ans[1]) {
                    if (!Q.empty()) { ans[1] = Q.front() == y; Q.pop(); }
                    else ans[1] = 0;
                }
                if (ans[2]) {
                    if (!pq.empty()) { ans[2] = pq.top() == y; pq.pop(); }
                    else ans[2] = 0;
                }
            }
        }
        int cnt = 0;
        REP(i,3) cnt += ans[i];
        if (cnt > 1) puts("not sure");
        else if (!cnt) puts("impossible");
        else {
            if (ans[0]) puts("stack");
            if (ans[1]) puts("queue");
            if (ans[2]) puts("priority queue");
        }
    }

    return 0;
}












































































