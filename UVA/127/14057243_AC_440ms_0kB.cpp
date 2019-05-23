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
const int MAXN  = 70, INF = ~0U>>1, MOD = ~0U>>1;

char s[52][3];
int lt[52][52], rear[52];

bool solve(int i, int n)
{
    int j = i;
    for (int cnt = 0; j>=0 && cnt<n; ) if (rear[--j]) cnt++;
    if (j>=0) {
        int x = lt[j][rear[j]-1], y = lt[i][rear[i]-1];
        if (s[x][0]==s[y][0] || s[x][1]==s[y][1]) {
            lt[j][rear[j]++] = lt[i][--rear[i]];
            return true;
        }
    }
    return false;
}
void printAns()
{
    int cnt = 0;
    REP(i,52)if(rear[i])cnt++;
    printf("%d pile%s remaining:", cnt, cnt>1 ? "s" : ""); //细节
    REP(i,52)if(rear[i])printf(" %d", rear[i]);
    puts("");
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%s", s[0]), s[0][0] != '#') {
        FOR(i,1,51)scanf("%s", s[i]);
        REP(i,52) { lt[i][0] = i; rear[i] = 1; }
        REP(i,52) if (rear[i] && (solve(i,3) || solve(i,1))) { i = 0; continue; }
        printAns();
    }

    return 0;
}

































