

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







int T, n, ind, pri, a[10];
struct job {
    int priority, isTarget;
    job (int p, int t) : priority(p), isTarget(t) {}
};
bool jdg(int p)
{
    FOR(i,p+1,9) if (a[i]) return false;
    return true;
}

int main()
{
    #ifdef LOCAL
        freopen("i", "r", stdin);
        //freopen("o", "w", stdout);
    #endif //LOCAL

    cin >> T;
    while (T--) {
        queue<job> q;
        memset(a, 0, sizeof(a));
        cin >> n >> ind;
        REP(i,n) {
            cin >> pri;
            a[pri]++;
            q.push(job(pri, i == ind));
        }
        int cnt = 0;
        while (true) {
            if (jdg(q.front().priority)) {
                cnt++;
                if (q.front().isTarget) { cout << cnt << endl; break; }
                else { a[q.front().priority]--; q.pop(); }
            } else { q.push(q.front()); q.pop(); }
        }
    }


































    return 0;
}





