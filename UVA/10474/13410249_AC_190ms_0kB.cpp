

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
typedef long long LL;
const int MAXN  = 1e6, INF = ~0U>>1, MOD = ~0U>>1;












int N,T,a[2][MAXN],kase(0),t;
struct cmp { inline bool operator() (const int& a, const int& b) { return a < b; } };

bool read()
{
    cin>>N>>T;
    if(!N)return false;
    REP(i,N) {cin>>a[0][i]; a[1][i]=i+1;}
    return true;
}
void solve()
{
    stable_sort(a[0],a[0]+N,cmp());
    printf("CASE# %d:\n", ++kase);
    while (T--) {
        cin>>t;
        int index = lower_bound(a[0],a[0]+N,t) - a[0];
        if (a[0][index] == t)
            printf("%d found at %d\n", t, a[1][index]);
        else printf("%d not found\n", t);
    }
}


int main()
{
#ifdef LOCAL
    //freopen("i", "r", stdin);
    //freopen("o", "w", stdout);
#endif //LOCAL

#ifdef _DEBUG

#endif //_DEBUG

    while (read()) {
        solve();
    }



















    return 0;
}
