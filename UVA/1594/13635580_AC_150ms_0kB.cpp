

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
#include <unordered_map>
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
const int MAXN  = 1e4, INF = ~0U>>1, MOD = ~0U>>1;








int T, n, a[20], zero[20];


int main()
{
    #ifdef LOCAL
        freopen("i", "r", stdin);
        //freopen("o", "w", stdout);
    #endif //LOCAL

    cin >> T;
    while (T--) {
        cin >> n;
        REP(i,n) cin >> a[i];
        bool flag(true);
        REP(i,1000) {
            a[n] = a[0];
            REP(i,n) a[i] = abs(a[i]-a[i+1]);
            if (!memcmp(a, zero, n*4)) { puts("ZERO"); flag = false; break; }
        }
        if (flag) puts("LOOP");
    }















    return 0;
}





