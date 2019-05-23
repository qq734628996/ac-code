

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









struct id {
    int a, b;
    id (int _a, int _b) : a(_a), b(_b) {}
    bool operator < (const id& o) const { //重载注意加const(c++强类型匹配)
        if (a == o.a) return b < o.b;
        return a < o.a;
    }
};

map<string, int> IDcache;
vector<string> Setcache;
int ID(string& str)
{
    if (IDcache.count(str)) return IDcache[str];
    Setcache.push_back(str);
    return IDcache[str] = SZ(Setcache) - 1;
}


int main()
{
    #ifdef LOCAL
        freopen("i", "r", stdin);
        freopen("o", "w", stdout);
    #endif //LOCAL

    int n, m;
    string str[15];

    while (~scanf("%d%d\n", &n, &m)) {
        IDcache.clear();
        Setcache.clear();
        bool OK = false;
        struct {
            map<id, int> mp;
        }a[m][m];

        REP(k,n) { //行数
            REP(i,m-1) getline(cin, str[i], ',');
            getline(cin, str[m-1]);

            //REP(i,m) DEBUG(str[i])

            for (int i = 0; !OK && i < m-1; i++) {
                for (int j = i+1; !OK && j < m; j++) {
                    id tmp(ID(str[i]), ID(str[j]));
                    if ( a[i][j].mp.count(tmp) ) {
                        printf("NO\n%d %d\n%d %d\n", a[i][j].mp[tmp]+1, k+1, i+1, j+1);
                        OK = true;
                    } else a[i][j].mp[tmp] = k;
                }
            }
        }

        if (!OK) puts("YES");
    }
























    return 0;
}





