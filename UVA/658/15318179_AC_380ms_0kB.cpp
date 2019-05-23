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
const int MAXN = 1e2+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n, m, c[105], state[105][4], kase;
char s[25], t[25];
priority_queue<pii> Q;
unordered_set<int> vis;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d", &n, &m), n) {
        printf("Product %d\n", ++kase);
        memset(state, 0, sizeof(state));
        REP(i,m) {
            scanf("%d%s%s", &c[i], s, t);
            REP(j,n) {
                if (s[j] == '+') state[i][0] |= (1<<j);
                if (s[j] == '-') state[i][1] |= (1<<j);
                if (t[j] == '+') state[i][2] |= (1<<j);
                if (t[j] == '-') state[i][3] |= (1<<j);
            }
        }
        while (!Q.empty()) Q.pop();
        vis.clear();
        Q.push(pii(-0, (1<<n)-1));
        bool fail = true;
        while (!Q.empty()) {
            int d = -Q.top().fi, u = Q.top().se; Q.pop();
            if (vis.count(u)) continue;
            vis.insert(u);
            if (!u) { fail = false; printf("Fastest sequence takes %d seconds.\n", d); break; }
            REP(i,m) if (((u & state[i][0]) == state[i][0]) && ((u & ~state[i][1]) == u)) {
                int v = u;
                v |= state[i][2];
                v &= ~state[i][3];
                if (v != u) Q.push(pii(-d-c[i], v));
            }
        }
        if (fail) puts("Bugs cannot be fixed.");
        puts("");
    }

    return 0;
}


















































































