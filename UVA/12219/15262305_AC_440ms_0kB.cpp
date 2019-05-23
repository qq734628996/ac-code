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
const int MAXN = 4e5+5, INF = 0x3f3f3f3f, MOD = 1e9+7;

char s[MAXN];
int T, vis[MAXN], f[MAXN], mi[MAXN], id;
struct tree {
    string name;
    int lc, rc;
    bool operator<(const tree& t) const {
        if (lc != t.lc) return lc < t.lc;
        if (rc != t.rc) return rc < t.rc;
        return name < t.name;
    }
};
vector<tree> treeSet;
map<tree, int> mp;
int ID(tree& t)
{
    if (mp.count(t)) return mp[t];
    treeSet.pb(t);
    return mp[t] = SZ(treeSet) - 1;
}

int build(int l, int r)
{
    tree t;
    for (; l <= r && s[l] != '('; l++) t.name.pb(s[l]);
    if (l > r) {
        t.lc = t.rc = -1;
    } else {
        t.lc = build(l+1, mi[l]-1);
        t.rc = build(mi[l]+1, r-1);
    }
    return ID(t);
}

void print(int rt)
{
    if (vis[rt]) printf("%d", vis[rt]);
    else {
        vis[rt] = ++id;
        tree& t = treeSet[rt];
        cout << t.name;
        if (~t.lc) {
            putchar('(');
            print(t.lc);
            putchar(',');
            print(t.rc);
            putchar(')');
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        int cnt = 0, len = strlen(s);
        REP(i,len) {
            switch (s[i]) {
                case '(' : f[++cnt] = i; break;
                case ')' : cnt--; break;
                case ',' : mi[f[cnt]] = i; break;
            }
        }
        treeSet.clear(); mp.clear();
        int rt = build(0, len-1);
        id = 0; memset(vis, 0, sizeof(vis));
        print(rt);
        puts("");
    }

    return 0;
}


















































































