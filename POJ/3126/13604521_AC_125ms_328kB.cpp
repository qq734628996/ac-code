

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
#define SZ(x) (int)((x).size())
typedef long long LL;
const int MAXN  = 1e4, INF = ~0U>>1, MOD = ~0U>>1;










int a[MAXN], vis[MAXN]; //a存质数
bool isPrime(int x)
{
    if (!(x & 1)) return false;
    int sqr = floor(sqrt((float)x) + 0.5);
    for (int i = 3; i <= sqr; i += 2)
        if (!(x % i)) return false;
    return true;
}
void genPrime()
{
    FOR(i,1000,9999)
        if (isPrime(i)) a[i] = 1;
}

int bfs(int m, int n)
{
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(m); vis[m] = 1;

    while (true) {
        int t = q.front(); q.pop();
        if (t == n) return vis[t]-1;

        char buf[10];
        int tt;
        REP(i,4) {
            buf[0] = '\0';
            sprintf(buf, "%4d", t);
            assert(buf[4]=='\0');
            buf[i] = '0';

            REP(j,10) {
                sscanf(buf, "%d", &tt);
                buf[i]++;

                if (1000 <= tt && a[tt] && !vis[tt]) {
                    //DEBUG(tt)
                    assert(1000<=tt && tt<=9999);
                    q.push(tt);
                    vis[tt] = vis[t] + 1;
                }
            }
        }
    }
}

int main()
{
    #ifdef LOCAL
        freopen("i", "r", stdin);
        //freopen("o", "w", stdout);
    #endif //LOCAL
    genPrime();
    int T, m, n;
    cin >> T;
    while (T--) {
        cin >> m >> n;
        cout << bfs(m, n) << endl;
    }

    return 0;
}





