#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>

#include <iostream>
#include <algorithm>
//#include <unordered_map>
//#include <unordered_set>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
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
const int MAXN = 5e4+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 1000000007;

int n, q, a[MAXN], mi[MAXN][20], ma[MAXN][20];
void RMQ_init()
{
    FOR(i,1,n) mi[i][0] = a[i];
    for (int j = 1; (1<<j) <= n; j++) {
        for (int i = 1; i+(1<<j)-1 <= n; i++) {
            mi[i][j] = min(mi[i][j-1], mi[i+(1<<(j-1))][j-1]);
        }
    }
    FOR(i,1,n) ma[i][0] = a[i];
    for (int j = 1; (1<<j) <= n; j++) {
        for (int i = 1; i+(1<<j)-1 <= n; i++) {
            ma[i][j] = max(ma[i][j-1], ma[i+(1<<(j-1))][j-1]);
        }
    }
}
int RMQ(int L, int R)
{
    int k = 0;
    while ((1<<(k+1)) <= R-L+1) k++;
    return max(ma[L][k],ma[R-(1<<k)+1][k]) - min(mi[L][k],mi[R-(1<<k)+1][k]);
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d%d", &n, &q);
    FOR(i,1,n) scanf("%d", &a[i]);
    RMQ_init();
    while (q--) {
        int x, y; scanf("%d%d", &x, &y);
        printf("%d\n", RMQ(x,y));
    }

    return 0;
}












































































