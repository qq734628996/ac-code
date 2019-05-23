

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







string t1, t2, s1, s2;
int T, n, kase(0);

bool check(int index, int k)
{
    int i = index+1;
    for ( ; k >= 0; k--) {
        if (i <= n) i <<= 1;
        else i = 2*(i-n)-1;
    }
    return s1[index] == s2[i-1];
}
int jdg()
{
    REP(i,2*n) {
        bool OK(true);
        REP(j,SZ(s1)) {
            if (!check(j,i)) { OK = false; break; }
        }
        if (OK) return i+1;
    }
    return -1;
}

int main()
{
    #ifdef LOCAL
        freopen("i", "r", stdin);
        //freopen("o", "w", stdout);
    #endif //LOCAL

    cin >> T;
    while (T--) {
        cin >> n >> t1 >> t2 >> s2;
        s1 = t1 + t2;
        assert(SZ(s1)==SZ(s2));
        printf("%d %d\n", ++kase, jdg());
    }

    return 0;
}