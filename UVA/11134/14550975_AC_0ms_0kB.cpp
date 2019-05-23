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
const int MAXN  = 5e3+5, INF = ~0U>>1, MOD = ~0U>>1;

int n, res[2][MAXN];
struct piece {
    int l, r, id;
    bool operator<(const piece& p) const {
        return r<p.r || (r==p.r && l<p.l);
    }
};
vector<piece> p[2];
vector<pii> ans[2];

bool place(int i)
{
    sort(ALL(p[i]));
    REP(j,n) {
        bool fail = true;
        int st = p[i][j].l-1, ed = p[i][j].r-1;
        FOR(k,st,ed) if (!res[i][k]) {
            res[i][k] = p[i][j].id+1;
            fail = false;
            break;
        }
        if (fail) return false;
    }
    return true;
}

bool jdg()
{
    memset(res, 0, sizeof(res));
    REP(i,2) if (!place(i)) return false;
    return true;
}

void getans(int i)
{
    ans[i].clear();
    REP(j,n) ans[i].push_back(pii(res[i][j], j+1));
    sort(ALL(ans[i]));
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n), n) {
        REP(i,2) p[i].clear();
        int a,b,c,d;
        REP(i,n) {
            scanf("%d%d%d%d", &a,&b,&c,&d);
            p[0].push_back((piece){a,c,i});
            p[1].push_back((piece){b,d,i});
        }
        if (jdg()) {
            REP(i,2) getans(i);
            REP(j,n) printf("%d %d\n", ans[0][j].second, ans[1][j].second);
        } else puts("IMPOSSIBLE");
    }

    return 0;
}












































































