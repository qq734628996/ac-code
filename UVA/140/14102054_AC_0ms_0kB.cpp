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
const int MAXN  = 105, INF = ~0U>>1, MOD = ~0U>>1;

int G[30][30], Set[30], a[30], vis[30], n, minl, ans[30];

bool read()
{
    char ch = getchar();
    if (ch == '#') return false;
    memset(G, 0, sizeof(G));
    memset(Set, 0, sizeof(Set));
    int i = ch - 'A', j;
    while ((ch = getchar()) != '\n') {
        if (ch == ';') i = getchar() - 'A';
        else if (isalpha(ch)) {
            j = ch - 'A';
            G[i][j] = G[j][i] = Set[i] = Set[j] = 1;
        }
    }
    n = 0;
    REP(i,26)if(Set[i])n++;
    return true;
}

void dfs(int cur, int maxl)
{
    if (cur == n) {
        if (maxl < minl) {
            minl = maxl;
            memcpy(ans, a, sizeof(int)*n);
        }
        return;
    }
    REP(i,26)if(Set[i] && !vis[i]) {
        int cnt = 0;
        REP(j,26)if(G[i][j] && !vis[j])cnt++;
        if (cnt >= minl) continue;
        cnt = 0;
        REP(j,cur) if (G[i][a[j]]) cnt = max(cnt, cur-j);
        if (cnt >= minl) continue;
        a[cur] = i;
        vis[i] = 1;
        dfs(cur + 1, max(maxl, cnt));
        vis[i] = 0;
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (read()) {
        minl = INF;
        //memset(a, 0, sizeof(a));
        //memset(ans, 0, sizeof(ans));
        memset(vis, 0, sizeof(vis));
        dfs(0, 0);
        REP(i,n)printf("%c ", ans[i]+'A');
        printf("-> %d\n", minl);
    }

    return 0;
}

































