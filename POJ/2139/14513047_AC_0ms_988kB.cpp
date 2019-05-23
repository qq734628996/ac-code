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
const int MAXN  = 305, INF = 0x3f3f3f3f, MOD = ~0U>>1;

int a[MAXN][MAXN], b[MAXN], n, m;

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    memset(a, 0x3f, sizeof(a));
    scanf("%d%d", &n, &m);
    while (m--) {
        int x; scanf("%d", &x);
        REP(i,x) scanf("%d", &b[i]);
        REP(i,x)FOR(j,i+1,x-1) a[b[i]][b[j]] = a[b[j]][b[i]] = 1;
    }
    //FOR(i,1,n){FOR(j,1,n) printf("%11d", a[i][j]); puts("");}
    FOR(k,1,n)FOR(i,1,n)FOR(j,1,n) a[i][j] = min(a[i][j], a[i][k]+a[k][j]);
    //FOR(i,1,n){FOR(j,1,n) printf("%11d", a[i][j]); puts("");}
    int ans = INF;
    FOR(i,1,n) {
        int sum = 0;
        FOR(j,1,n) if (i != j) sum += a[i][j];
        ans = min(ans, sum);
    }
    printf("%d\n", ans*100/(n-1));

    return 0;
}

















































































