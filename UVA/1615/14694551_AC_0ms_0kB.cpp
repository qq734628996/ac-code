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
const int MAXN  = 1e5+5, INF = ~0U>>1, MOD = ~0U>>1;

int L, D, n, x, y;
double l, r, sqr;
typedef pair<double, double> pdd;
vector<pdd> V;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d%d%d", &L, &D, &n)) {
        V.clear();
        REP(i,n) {
            scanf("%d%d", &x, &y);
            sqr = sqrt(D*D - y*y);
            l = x-sqr; r = x+sqr;
            if (l < 0) l = 0;
            if (r > L) r = L;
            V.push_back(pdd(r, -l));
        }
        sort(ALL(V));
        int cnt = 0;
        double last = -1;
        REP(i,n) {
            if (-V[i].second > last) {
                last = V[i].first;
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}










































































