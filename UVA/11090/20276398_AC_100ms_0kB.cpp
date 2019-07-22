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
const int MAXN = 1e2+9, MAXM = 1e5+9;

int to[MAXM],f[MAXN],nxt[MAXM],tot;
double dis[MAXM];
void init(){ tot=0; memset(f,-1,sizeof(f)); }
void add(int u, int v, int w)
{
    to[tot]=v;
    dis[tot]=w;
    nxt[tot]=f[u];
    f[u]=tot++;
}
int n,m,inq[MAXN];
double d[MAXN];
bool spfa()
{
    memset(inq,0,sizeof(inq));
    memset(d,0,sizeof(d));
    int cnt=0;
    queue<int> Q;
    FOR(i,1,n) Q.push(i);
    while (!Q.empty()) {
        int u=Q.front(); Q.pop();
        inq[u]=0;
        for (int i=f[u]; ~i; i=nxt[i]) {
            int v=to[i];
            double w=dis[i];
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
bool jdg(double x)
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

    int T; scanf("%d", &T);
    FOR(kase,1,T) {
        init();
        scanf("%d%d", &n,&m);
        int ma=0;
        REP(i,m) {
            int x,y,z; scanf("%d%d%d", &x,&y,&z);
            add(x,y,z);
            ma=max(ma,z);
        }
        printf("Case #%d: ", kase);
        if (!jdg(ma+1)) puts("No cycle found.");
        else {
            double l=0, r=ma;
            while (r-l>1e-3) {
                double m=(l+r)/2;
                if (jdg(m)) r=m;
                else l=m;
            }
            printf("%.2f\n", (l+r)/2);
        }
    }

    return 0;
}

































