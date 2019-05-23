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
typedef pair<int, int> pii;
const int MAXN  = 7e4, INF = ~0U>>1, MOD = ~0U>>1;

int a[7][8], ans[7][8], vis[30], kase, solution, cnt;
const int r[] = { 0, 1 };
const int c[] = { 1, 0 };
#define vld(x,y) (0<=(x) && (x)<7 && 0<=(y) && (y)<8)

int ID(int m, int n)
{
    if (n < m) swap(m, n);
    return 1 + (13-m)*m/2 + n;
}

void dfs(int si)
{
    if (cnt == 28) {
        if (!solution) printf("Maps resulting from layout #%d are:\n\n\n", kase);
        solution++;
        REP(i,7){ REP(j,8) printf("%4d", ans[i][j]); puts(""); }
        printf("\n\n");
        return;
    }
    for (int i = si; i < 7; i++) {
        for (int j = 0; j < 8; j++) {
            if (ans[i][j]) continue;
            REP(k,2) {
                int x = i+r[k], y = j+c[k];
                if (vld(x,y) && !ans[x][y]) {
                    int id = ID(a[i][j], a[x][y]);
                    if (vis[id]) continue;

                    cnt++;
                    ans[i][j] = ans[x][y] = id;
                    vis[id] = 1;
                    dfs(i);
                    cnt--;
                    ans[i][j] = ans[x][y] = 0;
                    vis[id] = 0;
                }
            }
            return;
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d", &a[0][0])) {
        if (kase) printf("\n\n\n\n\n");
        printf("Layout #%d:\n\n\n", ++kase);
        REP(i,7)REP(j,8)if(i || j) scanf("%d", &a[i][j]);
        REP(i,7){ REP(j,8) printf("%4d", a[i][j]); puts(""); } puts("");

        solution = cnt = 0;
        dfs(0);
        printf("There are %d solution(s) for layout #%d.\n", solution, kase);
    }

    return 0;
}

















































































