#include <bits/stdc++.h>
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
const int MAXN  = 1e2+5, INF = ~0U>>1;



int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int ch;
    char* s[4] = {"Apple", "iPhone", "iPod", "iPad"};
    int id1[4] = {0};
    char t[] = "Sony";
    int id2 = 0;

    while ((ch = getchar()) != EOF) {
        REP(i,4) {
            if (s[i][id1[i]] == '\0') {
                id1[i] = 0;
                puts("MAI MAI MAI!");
            } else if (s[i][id1[i]] == ch) id1[i]++;
            else id1[i] = 0;
        }
        if (t[id2] == '\0') {
            id2 = 0;
            puts("SONY DAFA IS GOOD!");
        } else if (t[id2] == ch) id2++;
        else id2 = 0;
    }

    return 0;
}



































