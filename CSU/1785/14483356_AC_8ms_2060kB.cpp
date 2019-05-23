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
#define MAXN 10005

int T, x, vis[MAXN], kase;
char s[5];

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    FOR(i,1,100) vis[i*i] = 1;
    scanf("%d", &T);
    while (T--) {
        int cnt = 0;
        scanf("%d", &x);
        sprintf(s, "%d", x);
        s[4] = '\0';
        REP(i,4) {
            char bak = s[i];
            REP(j,10) {
                if (i==0 && j==0) continue;
                if (j+'0' == bak) continue;
                s[i] = j + '0';
                sscanf(s, "%d", &x);
                if (vis[x]) cnt++;
            }
            s[i] = bak;
        }
        printf("Case %d: %d\n", ++kase, cnt);
    }

    return 0;
}















































































