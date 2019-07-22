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
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const int INF = 0x3f3f3f3f, MOD = 1000000007;
const double PI = acos(-1), EPS = 1e-15;
const int MAXN = 1e2+9, MAXM = 2e3+9;

int to[MAXM],f[MAXN],nxt[MAXM],tot;
void init()
{
    tot=0;
    memset(f,-1,sizeof(f));
}
void add(int u, int v)
{
    to[tot]=v;
    nxt[tot]=f[u];
    f[u]=tot++;
}
int n=52,m,kase;
LL d[MAXN];
int ID(char ch) { return islower(ch)?ch-'a':26+ch-'A'; }
char name(int id) { return id<26?id+'a':id-26+'A'; }
void dij(int s, int x)
{
    REP(i,52) d[i]=1e15;
    priority_queue<pll> pq;
    pq.push({d[s]=x,s});
    while (!pq.empty()) {
        int u=pq.top().se; pq.pop();
        LL w=1;
        if (u>=26) {
            w=d[u]/19;
            while (w!=(d[u]+w+19)/20) w++;
        }
        for (int i=f[u]; ~i; i=nxt[i]) {
            int v=to[i];
            if (d[v]>d[u]+w) {
                d[v]=d[u]+w;
                pq.push({-d[v],v});
            }
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &m)==1 && ~m) {
        init();
        char s[2],t[2];
        REP(i,m) {
            scanf("%s%s", s,t);
            int x=ID(s[0]), y=ID(t[0]);
            add(x,y), add(y,x);
        }
        int x;
        scanf("%d%s%s", &x,s,t);
        int st=ID(s[0]), ed=ID(t[0]);
        dij(ed,x);
        printf("Case %d:\n%lld\n", ++kase,d[st]);
        for (int u=st; u!=ed; ) {
            printf("%c-", name(u));
            int nxtu=u;
            for (int i=f[u]; ~i; i=nxt[i]) {
                int v=to[i];
                LL w=v<26?1:(d[u]+19)/20;
                if (d[v]==d[u]-w) {
                    if (nxtu==u || name(v)<name(nxtu)) nxtu=v;
                }
            }
            u=nxtu;
        }
        printf("%c\n", name(ed));
    }

    return 0;
}

































