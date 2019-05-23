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
const int MAXN  = 2e2+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n, d[MAXN][2], cnt;
bool f[MAXN][2];
string s, t;
vector<int> son[MAXN];

unordered_map<string, int> idmap;
int id(const string& str)
{
    if (idmap.count(str)) return idmap[str];
    return idmap[str] = ++cnt;
}

void init()
{
    FOR(i,0,n) son[i].clear();
    son[0].pb(1);
    idmap.clear(); cnt = 0;
    memset(d, -1, sizeof(d));
}

int dp(int i, int flag)
{
    int& ans = d[i][flag];
    bool& ok = f[i][flag];
    if (ans != -1) return ans;
    ans = flag;
    ok = true;
    if (!SZ(son[i])) return ans;
    if (flag) {
        REP(j,SZ(son[i])) ans += dp(son[i][j], 0);
        REP(j,SZ(son[i])) ok &= f[son[i][j]][0];
    } else {
        REP(j,SZ(son[i])) {
            int& u = son[i][j];
            int a = dp(u, 0), b = dp(u, 1);
            ans += max(a, b);
            if (a == b) ok = false;
            else if (a > b) ok &= f[u][0];
            else ok &= f[u][1];
        }
    }
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

     while (scanf("%d", &n), n) {
        init();
        cin >> s; id(s);
        FOR(i,2,n) cin >> s >> t, son[id(t)].pb(id(s));
        printf("%d ", dp(0, 0));
        puts(f[0][0] ? "Yes" : "No");
     }

    return 0;
}

//printf("%d %s\n", dp(0, 0), (f[0][0] ? "Yes" : "No")); //灵异事件！无法按照正常顺序打印！
//注意printf参数进栈顺序从右向左，由于前面函数尚未执行，所以后面结果自然不正确



















































































