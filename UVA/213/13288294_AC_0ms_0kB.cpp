#define LOCAL

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

int readNum(int n, int k) //读取一个n位k进制的整数
{
    char c; int num = 0;
    while ( n-- ) {
        c = getchar();
        if ( !isdigit(c) ) n++;
        else num = num * k + c - '0';
    }
    return num;
}



int main()
{
#ifdef LOCAL
    //freopen("i", "r", stdin); //提交时不要忘记解注释
    //freopen("o", "w", stdout);
#endif
    string s;
    int weiShu, t;
    char c;
    while (getline(cin, s)) {                                  //DEBUG(s)
        while (true) {
            weiShu = readNum(3, 2);
            if (weiShu == 0) { getchar(); cout << endl; break; }          //DEBUG(weiShu)
                                //注意丢弃换行符
            while (true) {
                t = readNum(weiShu, 2);
                if (t == (1 << weiShu) - 1) break;            //DEBUG(t)
                putchar( s[ (1 << weiShu) - weiShu - 1 + t ] );
            }
        }
    }
    return 0;
}





































