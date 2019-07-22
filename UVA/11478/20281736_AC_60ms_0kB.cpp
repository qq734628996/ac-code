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
const int MAXN = 5e2+9, MAXM = 3e3+9;

int to[MAXM],dis[MAXM],f[MAXN],nxt[MAXM],tot;
void init(){ tot=0; memset(f,-1,sizeof(f)); }
void add(int u, int v, int w)
{
    to[tot]=v;
    dis[tot]=w;
    nxt[tot]=f[u];
    f[u]=tot++;
}
int n,m,d[MAXN],inq[MAXN];
bool spfa()
{
    memset(d,0,sizeof(d));
    memset(inq,0,sizeof(inq));
    int cnt=0;
    queue<int> Q;
    FOR(i,1,n) Q.push(i);
    while (!Q.empty()) {
        int u=Q.front(); Q.pop();
        inq[u]=0;
        for (int i=f[u]; ~i; i=nxt[i]) {
            int v=to[i], w=dis[i];
            if (d[v]>d[u]+w) {
                d[v]=d[u]+w;
                if (!inq[v]) {
                    inq[v]=1;
                    Q.push(v);
                    if (++cnt>2*(n+m)) return true;
                }
            }
        }
    }
    return false;
}
bool jdg(int x)
{
    REP(i,tot) dis[i]-=x;
    bool res=spfa();
    REP(i,tot) dis[i]+=x;
    return res;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d", &n,&m)==2) {
        init();
        int l=1,r=0;
        REP(i,m) {
            int x,y,z; scanf("%d%d%d", &x,&y,&z);
            add(x,y,z);
            r=max(r,z);
        }
        if (jdg(l)) puts("No Solution");
        else if (!jdg(r)) puts("Infinite");
        else {
            while (r-l>0) {
                int m=(l+r)/2;
                if (jdg(m)) r=m;
                else l=m+1;
            }
            printf("%d\n", r-1);
        }
    }

    return 0;
}

































