

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











int main()
{
    #ifdef LOCAL
        freopen("i", "r", stdin);
        freopen("o", "w", stdout);
    #endif //LOCAL

    int n, t;
    while (cin >> n, n) {
        queue<int> q;
        FOR(i,1,n) q.push(i);
        printf("Discarded cards:");
        if (n != 1) putchar(' ');
        while (q.size() > 1) {
            t = q.front(); q.pop();
            cout << t;
            if (q.size() > 1) cout << ", ";
            q.push(q.front()); q.pop();
        }
        printf("\nRemaining card: %d\n", q.front());
    }















    return 0;
}





