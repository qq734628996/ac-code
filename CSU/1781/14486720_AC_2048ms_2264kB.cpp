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
//#include <unordered_set>
#include <sstream>
#include <string>
#include <vector>
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
//const int MAXN  = 205, INF = ~0U>>1, MOD = ~0U>>1;
#define MAXN 1005

LL x, a, b;
int kase;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (cin >> x) {
        printf("Case %d: ", ++kase);
        if (x == 1) { puts("Impossible"); continue; }
        bool flag = false;
        for (int maxd = 12; maxd >= 1 && !flag; maxd--) {
                //DEBUG(maxd)
            bool ok = true;
            int i = (int)pow(2, log(x)/maxd) - maxd;
            if (i < 1) i = 1;
            for ( ; ok && !flag; i++) {
                    //DEBUG(i)
                LL res = 1;
                for (int j = i; j < i+maxd; j++) {
                    res *= j;
                }
                if (res == x) {
                    flag = true;
                    a = i+maxd-1, b = i-1;
                } else if (res > x) {
                    ok = false;
                }
            }
        }
        if (b<1) b = 1;
        if (flag) cout << a << ' ' << b << endl;
        else puts("Impossible");
    }

    return 0;
}















































































