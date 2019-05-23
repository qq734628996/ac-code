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
#define MAXN 505

int n, m, a[MAXN][MAXN], kase;
LL r[MAXN], c[MAXN], cnt;
int ei, ej;
set<pii> ans;

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d%d", &n, &m)) {
        REP(i,n)REP(j,m) scanf("%d", &a[i][j]);
        memset(r, 0, sizeof(r));
        memset(c, 0, sizeof(c));
        REP(i,n)REP(j,m) r[i] += a[i][j], c[j] += a[i][j];
        ei = ej = 0;
        REP(i,n) if (r[i] > r[ei]) ei = i;
        REP(j,m) if (c[j] > c[ej]) ej = j;
        cnt = 0;
        ans.clear();
        REP(i,n)REP(j,m) if (r[i]+c[j]-a[i][j] > cnt) cnt = r[i]+c[j]-a[i][j];
        REP(i,n)REP(j,m) if (r[i]+c[j]-a[i][j] == cnt) ans.insert(pii(i,j));
        printf("Case %d: ", ++kase);
        if (ans.count(pii(ei, ej))) puts("Weak");
        else puts("Strong");
    }

    return 0;
}















































































