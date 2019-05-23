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
const int MAXN = 20, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 10007;

int T,n,a[MAXN][MAXN],b[MAXN][MAXN],ans;

void gen()
{
    FOR(i,1,n-1)REP(j,n) {
        int cnt = 0;
        if (0 <= j-1) cnt += b[i-1][j-1];
        if (j+1 < n) cnt += b[i-1][j+1];
        if (0 <= i-2) cnt += b[i-2][j];
        b[i][j] = cnt&1;
    }
}

void upd()
{
    int cnt = 0;
    REP(i,n)REP(j,n) {
        if (a[i][j] && !b[i][j]) {
            cnt = INF;
            break;
        }
        if (!a[i][j] && b[i][j]) cnt++;
    }
    ans = min(ans, cnt);
}

void dfs(int d)
{
    if (d == n) gen(),upd();
    else {
        b[0][d] = 1;
        dfs(d+1);
        b[0][d] = 0;
        dfs(d+1);
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    FOR(kase,1,T) {
        scanf("%d", &n);
        REP(i,n)REP(j,n) scanf("%d", &a[i][j]);
        if (n == 1) printf("Case %d: 0\n", kase);
        else {
            ans = INF;
            dfs(0);
            if (ans == INF) ans = -1;
            printf("Case %d: %d\n", kase, ans);
        }
    }

    return 0;
}











































































