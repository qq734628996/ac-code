

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
const int MAXN  = 1e4+5, INF = ~0U>>1, MOD = ~0U>>1;










typedef pair<int, int> pint;
int n, a[26][2];
string str;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    cin >> n;
    REP(i,n) { cin >> str; cin >> a[str[0]-'A'][0] >> a[str[0]-'A'][1]; }

    while (cin >> str) {
        stack<pint> s;
        int ans(0), flag(true);
        REP(i,SZ(str)) {
            if (isupper(str[i])) s.push(pint(a[str[i]-'A'][0], a[str[i]-'A'][1]));
            else if (str[i] == ')') {
                pint m2 = s.top(); s.pop();
                pint m1 = s.top(); s.pop();
                if (m1.second != m2.first) { flag = false; break; }
                else {
                    ans += m1.first*m1.second*m2.second;
                    s.push(pint(m1.first, m2.second));
                }
            }
        }
        if (flag) printf("%d\n", ans);
        else puts("error");
    }















































    return 0;
}
