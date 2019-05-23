

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
#define MAXN (20)
typedef long long LL;
const int INF = ~0U>>1, MOD = ~0U>>1;

int n, T, kase, cnt;
bool a[MAXN][MAXN][2];

bool read()
{
    memset(a,0,sizeof(a));
    if (!(cin >> n >> T)) return false;
    char c; int i, j;
    while (T--) {
        cin >> c >> i >> j;
        if (c == 'H') a[i][j][0] = 1;
        else a[j][i][1] = 1;
    }
    return true;
}
bool check(int i, int j, int len)
{
    FOR(x,i,i+len-1)if(!a[x][j][1] || !a[x][j+len][1])return false;
    FOR(x,j,j+len-1)if(!a[i][x][0] || !a[i+len][x][0])return false;
    return true;
}
int Count(int len)
{
    int cnt = 0;
    FOR(i,1,n-len)FOR(j,1,n-len) cnt += check(i, j, len); //DEBUG(cnt)
    return cnt;
}
void solve()
{
#ifdef _DEBUG
    cout << "--------------------------------------\n";
    FOR(i,1,n) {
        FOR(j,1,n)
            if (a[i][j][0]) cout << '-';
            else cout << ' ';
        cout<<endl;
        FOR(j,1,n)
            if (a[i][j][1]) cout << '|';
            else cout << ' ';
        cout<<endl;
    }
    cout << "--------------------------------------\n";
#endif //_DEBUG
    if (kase) cout << "\n**********************************\n\n";
    printf("Problem #%d\n\n", ++kase);
    bool flag = false;
    FOR(i,1,n-1) {
        cnt = Count(i); //DEBUG(cnt)
        if (cnt) {
            printf("%d square (s) of size %d\n", cnt, i);
            flag = true;
        }
    }
    if (!flag) cout << "No completed squares can be found.\n";
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
