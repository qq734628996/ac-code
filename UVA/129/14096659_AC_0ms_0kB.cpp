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

int k, n, cnt, a[MAXN];
int dfs(int cur)
{
    if (cnt++ == k) {
        REP(i,cur-1) {
            putchar(a[i] + 'A');
            if (!((i+1) % 64)) puts("");
            else if (!((i+1) % 4)) putchar(' ');
        }
        printf("%c\n%d\n", a[cur-1] + 'A', cur);
        return 1;
    }
    REP(i,n) {
        a[cur] = i;
        bool ok = true;
        for (int len = 1; len*2 <= cur+1; len++) {
            bool flag = true;
            REP(j,len) if (a[cur-j] != a[cur-len-j]) { flag = false; break; }
            if (flag) { ok = false; break; }
        }
        if (ok && dfs(cur + 1)) return 1;
    }
    return 0;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d", &k, &n), k) {
        cnt = 0;
        dfs(0);
    }

    return 0;
}

































