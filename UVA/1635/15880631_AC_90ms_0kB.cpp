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
const int MAXN = 1e5+5, MAXM = 1e2+5, INF = 0x3f3f3f3f, MOD = 1e9+7;

int n, m;
vector<pii> p;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d%d", &n, &m)) {
        p.clear();
        FOR(i,2,MAXN) {
            if (m % i == 0) {
                pii t(i,0);
                while (m % i == 0) {
                    m /= i;
                    t.se++;
                }
                p.pb(t);
            }
            if (m == 1) break;
        }
        if (m > 1) p.pb(pii(m,1));
        vector<int> ans;
        vector<pii> now(p);
        REP(i,SZ(now)) now[i].se = 0;
        int cnt = 0;
        FOR(i,1,n-1) {
            int t = n-i;
            REP(i,SZ(now)) while (t % now[i].fi == 0) {
                t /= now[i].fi;
                now[i].se++;
            }
            t = i;
            REP(i,SZ(now)) while (t % now[i].fi == 0) {
                t /= now[i].fi;
                now[i].se--;
            }
            bool ok = true;
            REP(i,SZ(now)) if (now[i].se < p[i].se) { ok = false; break; }
            if (ok) ans.pb(i+1);
        }
        printf("%d\n", SZ(ans));
        if (!SZ(ans)) { puts(""); continue; }
        REP(i,SZ(ans)-1) printf("%d ", ans[i]);
        printf("%d\n", ans[SZ(ans)-1]);
    }

    return 0;
}














































































