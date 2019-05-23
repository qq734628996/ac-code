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
const int MAXN  = 5e2+5, INF = ~0U>>1, MOD = ~0U>>1;



int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int n, x, y;
    while (scanf("%d", &n), n) {
        int cnt = 0;
        priority_queue<int, vector<int>, greater<int> > pq;
        REP(i,n) { scanf("%d", &x); pq.push(x); }
        while (SZ(pq) > 1) {
            x = pq.top(); pq.pop();
            y = pq.top(); pq.pop();
            pq.push(x+y);
            cnt += x+y;
        }
        printf("%d\n", cnt);
    }

    return 0;
}











































































