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
const int MAXN = 5e4+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 1e9+7;

int T, n;
char a[10][10], b[10][10];
vector<char> V[10];
string ans;

bool jdg(int i, int j)
{
    REP(k,i) if (b[k][j] == b[i][j]) return false;
    REP(k,6) if (a[k][j] == b[i][j]) return true;
    return false;
}

bool dfs(int i, int k)
{
    if (i == 5) return true;
    int num = 1;
    FOR(j,i+1,4) num *= SZ(V[j]);
    if (!num) return false;
    int j = k / num;
    if (j < SZ(V[i])) {
        ans.pb(V[i][j]);
        return dfs(i+1,k%num);
    } else return false;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        REP(i,6) scanf("%s", a[i]);
        REP(i,6) scanf("%s", b[i]);
        REP(j,5) V[j].clear();
        REP(i,6)REP(j,5) if (jdg(i,j)) V[j].pb(b[i][j]);
        REP(j,5) sort(ALL(V[j]));
        ans.clear();
        if (dfs(0,n-1)) cout << ans << endl;
        else puts("NO");
    }

    return 0;
}














































































