

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











#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

map<set<int>, int> M;
vector<set<int> > V;
stack<set<int> > S;

int ID(set<int> s)
{
    if (M.count(s)) return M[s];
    V.push_back(s);
    return M[s] = V.size() - 1;
}

int main()
{
#ifdef LOCAL
    freopen("i", "r", stdin);
    //freopen("o", "w", stdout);
#endif //LOCAL

#ifdef _DEBUG

#endif //_DEBUG

    int T, n;
    cin >> T;
    while (T--) {
        M.clear();
        V.clear();
        while (!S.empty()) S.pop();

        string str;
        cin >> n;
        while (n--) {
            cin >> str;
            if (str[0] == 'P') S.push(set<int>());
            else if (str[0] == 'D') S.push(S.top());
            else {
                set<int> s1 = S.top(); S.pop();
                set<int> s2 = S.top(); S.pop();
                set<int> s;

                if (str[0] == 'U') set_union(ALL(s1), ALL(s2), INS(s));
                else if (str[0] == 'I') set_intersection(ALL(s1), ALL(s2), INS(s));
                else {
                    s = s2;
                    s.insert(ID(s1));
                }
                S.push(s);
            }
            printf("%d\n", S.top().size());
        }

        puts("***");
    }



















    return 0;
}
