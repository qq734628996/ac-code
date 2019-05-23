

//#include "Head.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>

#include <iostream>
#include <algorithm>
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
#define MAXN (1e6)
typedef long long LL;
const int INF = ~0U>>1, MOD = ~0U>>1;



const int dir[6][5]={{1,2,4,3,1},{0,3,5,2,0},{0,1,5,4,0},{0,4,5,1,0},{0,2,5,3,0},{1,3,4,2,1}};

struct cube
{
    char side[6];
    bool operator== (const cube& c)
    {
        REP(i,6)
            if(side[0]==c.side[i]&&side[5]==c.side[5-i])
                REP(j,4)
                    if(side[1]==c.side[dir[i][j]]&&side[2]==c.side[dir[i][j+1]]
                    && side[4]==c.side[5-dir[i][j]]&&side[3]==c.side[5-dir[i][j+1]])
                        return true;
        return false;
    }
    void print(){REP(i,6)cout<<side[i];}
}a,b;
bool read()
{
    char s[20];
    if(scanf("%s",s)==-1)return false; //DEBUG(s)
    REP(i,6)a.side[i]=s[i];
    REP(i,6)b.side[i]=s[i+6];
    return true;
}
void solve()
{
    //a.print();cout<<' ';b.print();cout<<endl;
    puts(a==b?"TRUE":"FALSE");
}


int main()
{
#ifdef LOCAL
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);
#endif //LOCAL

#ifdef _DEBUG

#endif //_DEBUG

    while (read()) {
        solve();
    }



















    return 0;
}
