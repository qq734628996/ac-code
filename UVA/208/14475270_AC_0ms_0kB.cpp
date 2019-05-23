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
const int MAXN  = 25, INF = ~0U>>1, MOD = ~0U>>1;

int n, vis[MAXN], kase, ans[MAXN], cnt;
vector<int> E[MAXN];

bool bfs()
{
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(1);
    while (!Q.empty()) {
        int now = Q.front(); Q.pop();
        if (now == n) return true;
        for (auto& i : E[now]) if (!vis[i]) vis[i] = 1, Q.push(i);
    }
    return false;
}

void dfs(int now)
{
    if (ans[now] == n) {
        SHOW1(ans,now+1)
        cnt++;
        return;
    }

    int t = ans[now++];
    for (auto& i : E[t]) {
        if (!vis[i]) {
            ans[now] = i;
            vis[i] = 1;
            dfs(now);
            vis[i] = 0;
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d", &n)) {
        printf("CASE %d:\n", ++kase);

        REP(i,MAXN) E[i].clear();
        int x, y;
        while (scanf("%d%d", &x, &y), x) {
            E[x].push_back(y);
            E[y].push_back(x);
        }

        cnt = 0;
        if (bfs()) {
            memset(ans, 0, sizeof(ans));
            memset(vis, 0, sizeof(vis));
            REP(i,MAXN) sort(ALL(E[i]));
            ans[0] = 1; vis[1] = 1;
            dfs(0);
        }
        printf("There are %d routes from the firestation to streetcorner %d.\n", cnt, n);
    }

    return 0;
}















































































