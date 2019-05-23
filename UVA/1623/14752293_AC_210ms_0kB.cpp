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
const int MAXN  = 1e6+5, INF = ~0U>>1, MOD = ~0U>>1;

int T, n, m, a[MAXN], vis[MAXN], last[MAXN], ans[MAXN];
priority_queue<pii> Q;

inline void scanInt(int&x) {
    char ch;
    while (ch = getchar(), ch < '0' || ch > '9');
    x = ch - '0';
    while (ch = getchar(), ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0';
}

bool solve()
{
    memset(vis, 0, sizeof(int) * (n+1));
    memset(ans, 0, sizeof(int) * (m+1));
    memset(last, 0, sizeof(int) * (m+1));
    while (!Q.empty()) Q.pop();
    FOR(i,1,m) if (a[i]) {
        if (!vis[a[i]]) last[i] = 0;
        else last[i] = vis[a[i]];
        vis[a[i]] = i;
    }
    for (int i = m; i; i--) {
        if (a[i]) {
            Q.push(pii(last[i], a[i]));
        } else if (!Q.empty()) {
            if (Q.top().first > i) return false;
            ans[i] = Q.top().second;
            Q.pop();
        }
    }
    return Q.empty();
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanInt(T);
    while (T--) {
        scanInt(n); scanInt(m);
        FOR(i,1,m) scanInt(a[i]);
        if (!solve()) puts("NO");
        else {
            puts("YES");
            int cnt = 0;
            FOR(i,1,m) if (!a[i]) {
                if (cnt++) putchar(' ');
                printf("%d", ans[i]);
            }
            puts("");
        }
    }

    return 0;
}

//0 0 1 0 2 0 1 2
//0 0 1 2 0 2 0 1
//0 0 0 1 0 1 2 3





































































