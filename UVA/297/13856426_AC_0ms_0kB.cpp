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
const int MAXN  = 1e4+5, INF = ~0U>>1, MOD = ~0U>>1;






char a[32][32], ch;
void draw(int r, int c, int len)
{
    ch = getchar();
    if (ch == 'p') {
        int half = len>>1;
        draw(r,      c+half, half);
        draw(r,      c,      half);
        draw(r+half, c,      half);
        draw(r+half, c+half, half);
    } else if (ch == 'f') {
        int ie = r+len-1, je = c+len-1;
        FOR(i,r,ie)FOR(j,c,je)a[i][j] = 1;
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T;
    scanf("%d", &T); getchar();
    while (T--) {
        memset(a, 0, sizeof(a));
        draw(0, 0, 32); getchar();
        draw(0, 0, 32); getchar();
        int cnt(0);
        REP(i,32)REP(j,32)if(a[i][j]) cnt++;
        printf("There are %d black pixels.\n", cnt);
    }




























































    return 0;
}
