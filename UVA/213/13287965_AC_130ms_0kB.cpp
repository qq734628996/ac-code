

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <set>
#include <map>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define TR(e,x) for(typeof(x.begin()) e = x.begin(); e != x.end(); e++)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n-1) printf("%d ", A[i]); printf("%d\n", A[n-1]); }
#define SHOW2(A,m,n) { REP(i,m) { REP(j,n-1) printf("%d ", A[i][j]); printf("%d\n", A[i][n-1]); } }
#define PB push_back
#define MAXN (1e6)
typedef long long LL;
const int INF = ~0U>>1, MOD = ~0U>>1;



string s;
int weiShu, t;
char c;






int main()
{
    //freopen("i", "r", stdin); //提交时不要忘记解注释
    //freopen("o", "w", stdout);
    while (getline(cin, s)) {                                  //DEBUG(s)
        while (true) {
            weiShu = 0;
            REP(i,3) { cin >> c; weiShu = weiShu * 2 + c - '0'; }
            if (weiShu == 0) { getchar(); cout << endl; break; }          //DEBUG(weiShu)
                                //注意丢弃换行符
            while (true) {
                t = 0;
                REP(i,weiShu) {
                    cin >> c;
                    if (!isdigit(c)) { i--; continue; }
                    t = t * 2 + c - '0';
                }
                if (t == pow(2, weiShu) - 1) break;            //DEBUG(t)
                putchar( s[ pow(2,weiShu) - weiShu - 1 + t ] );
            }
        }
    }



















    return 0;
}





































