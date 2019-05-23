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
const int MAXN  = 7e4, INF = ~0U>>1, MOD = ~0U>>1;

vector<pii> V1, V2;
int n, x;

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &n);
    REP(i,n) { scanf("%d", &x); V1.push_back(pii(x,i)); }
    REP(i,n) { scanf("%d", &x); V2.push_back(pii(x,i)); }
    sort(ALL(V1)); sort(ALL(V2));
    if (V1[0].second != V2[0].second) printf("%d\n", V1[0].first+V2[0].first);
    else printf("%d\n", min(V1[0].first+V2[1].first, V1[1].first+V2[0].first));

    return 0;
}













































































