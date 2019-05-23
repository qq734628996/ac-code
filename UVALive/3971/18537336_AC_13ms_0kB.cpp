#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
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
const int MAXN = 1e3+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n,cnt,budget;
vector<pii> V[MAXN];
char s[23],t[23];
map<string,int> mp;
int ID(string s)
{
    if (mp.count(s)) return mp[s];
    return mp[s]=cnt++;
}
bool jdg(int x)
{
    int tot=0;
    REP(i,cnt) {
        int t=INF;
        REP(j,SZ(V[i])) if (x<=V[i][j].fi) t=min(t,V[i][j].se);
        if (t>budget) return false;
        tot+=t;
        if (tot>budget) return false;
    }
    return true;
}
int solve()
{
    int lo=INF,hi=-1;
    REP(i,cnt) {
        lo=min(lo,V[i][0].fi);
        hi=max(hi,V[i][SZ(V[i])-1].fi);
    }
    while (lo<hi) {
        int mi=lo+((hi-lo+1)>>1);
        if (jdg(mi)) lo=mi;
        else hi=mi-1;
    }
    return lo;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n,&budget);
        REP(i,cnt) V[i].clear();
        cnt=0;
        mp.clear();
        REP(i,n) {
            int x,y;
            scanf("%s%s%d%d", s,t,&x,&y);
            V[ID(s)].pb(pii(y,x));
        }
        REP(i,cnt) sort(ALL(V[i]));
        printf("%d\n", solve());
    }

    return 0;
}












































