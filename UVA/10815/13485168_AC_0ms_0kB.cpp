

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















set<string> s;

int main()
{
#ifdef LOCAL
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);
#endif //LOCAL

#ifdef _DEBUG

#endif //_DEBUG

    string buf, str;
    while (getline(cin, buf)) {
        REP(i,buf.size()) {
            if (isupper(buf[i])) buf[i] = tolower(buf[i]);
            if (!isalpha(buf[i])) buf[i] = ' ';
        }
        stringstream ss(buf);
        while (ss >> str) s.insert(str);
    }
    for (auto& i : s) cout << i << endl;


















    return 0;
}
