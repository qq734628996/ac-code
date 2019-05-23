

//#include "Head.h"
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
#include <sstream>
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
typedef long long LL;
const int MAXN  = 1e6, INF = ~0U>>1, MOD = ~0U>>1;












struct point {
    int x, y;
}p[100];
int n, len, ai[10], aj[10];

int bfs (int index, int k)
{
    if (k == 0) return 1;
    int res(0);
    for (int i = index; i < len; i++) {
        if (!ai[p[i].x] && !aj[p[i].y]) {
            ai[p[i].x] = aj[p[i].y] = 1;
            res += bfs(i+1, k-1);
            ai[p[i].x] = aj[p[i].y] = 0;
        }
    }
    return res;
}

int main()
{
#ifdef LOCAL
    //freopen("i", "r", stdin);
    //freopen("o", "w", stdout);
#endif //LOCAL

#ifdef _DEBUG

#endif //_DEBUG

    int k;
    while (cin >> n >> k, n != -1) {
        memset(ai, 0, sizeof(ai));
        memset(aj, 0, sizeof(aj));
        len = 0;

        getchar();
        REP(i,n) {
            REP(j,n) {
                if (getchar() == '#') {
                    p[len].x = i, p[len].y = j;
                    len++;
                }
            }
            getchar();
        }
        //REP(i,len) {DEBUG(i) DEBUG(p[i].x) DEBUG(p[i].y)}

        cout << bfs(0, k) << endl;
    }




















    return 0;
}
