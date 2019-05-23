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
#define MAXN 205

char s1[MAXN], s2[MAXN], a1[MAXN], a2[MAXN], b1[MAXN], b2[MAXN];
int kase;

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%s%s", s1, s2)) {
        printf("Case %d: ", ++kase);

        *strchr(s1,'.') = ' ';
        *strchr(s2,'.') = ' ';
        sscanf(s1, "%s%s", a1, b1);
        sscanf(s2, "%s%s", a2, b2);
        string a11(a1), b11(b1), a22(a2), b22(b2);
        if (a11 < a22) {
            puts("Smaller");
        } else if (a11 > a22) {
            puts("Bigger");
        } else {
            while (SZ(b11) != SZ(b22)) {
                if (SZ(b11) < SZ(b22)) b11.push_back('0');
                else b22.push_back('0');
            }
            if (b11 < b22) {
                puts("Smaller");
            } else if (b11 > b22) {
                puts("Bigger");
            } else {
                puts("Same");
            }
        }
    }

    return 0;
}















































































