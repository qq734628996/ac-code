#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
#define TR(e,x) for(auto e = x.begin(); e != x.end(); e++)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n-1) printf("%d ", A[i]); printf("%d\n", A[n-1]); }
#define SHOW2(A,m,n) { REP(i,m) { REP(j,n-1) printf("%d ", A[i][j]); printf("%d\n", A[i][n-1]); } }
#define pb push_back
#define fi first
#define se second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)((x).size())
typedef long long LL;
typedef pair<int, int> pii;
const int MAXN = 4e1+5, MAXM = 3e3+5, INF = 0x3f3f3f3f, MOD = 1e9+7;

int n, a[MAXN][4], b[MAXN], cnt, now, kase, res;
int d[MAXN][MAXN][MAXN][MAXN], vis[MAXN][MAXN][MAXN][MAXN];

void DFS(int i, int j, int k, int l);
int dfs(int i, int j, int k, int l, int x, int y)
{
    int ans = now;
    if (x < n) {
        if (++b[a[x+1][y]] & 1) {
            cnt++;
            if (cnt < 5) {
                DFS(i,j,k,l);
            }
            cnt--;
        } else {
            cnt--; now++;
            ans = now;
            res = max(res, now);
            DFS(i,j,k,l);
            cnt++; now--;
        }
        --b[a[x+1][y]];
    }
    return ans;
}

void DFS(int i, int j, int k, int l)
{
    int& ans = d[i][j][k][l];
    if (vis[i][j][k][l] == kase) return;
    vis[i][j][k][l] = kase;
    ans = 0;
    ans = max(ans, dfs(i+1,j,k,l,i,0));
    ans = max(ans, dfs(i,j+1,k,l,j,1));
    ans = max(ans, dfs(i,j,k+1,l,k,2));
    ans = max(ans, dfs(i,j,k,l+1,l,3));
    return;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n), n) {
        ++kase;
        FOR(i,1,n)REP(j,4) scanf("%d", &a[i][j]);
        memset(b, 0, sizeof(b));
        cnt = now = res = 0;
        DFS(0,0,0,0);
        printf("%d\n", res);
    }

    return 0;
}


















































































