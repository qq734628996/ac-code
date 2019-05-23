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

int T, n, x, y;
vector<pii> V;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        V.clear();
        REP(i,n) {
            scanf("%d%d", &x, &y);
            V.push_back(pii(x, y));
        }
        sort(ALL(V));
        int cnt = 0, r = V[0].second;
        for (int i = 1; i < SZ(V); i++) {
            x = V[i].first, y = V[i].second;
            if (x > r) {
                r = y;
                cnt++;
            } else r = y == r ? r : r+1;
        }
        printf("%d\n", cnt);
    }

    return 0;
}







































































