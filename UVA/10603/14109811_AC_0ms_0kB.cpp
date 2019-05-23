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
const int MAXN  = 205, INF = ~0U>>1, MOD = ~0U>>1, EPS = 1e-8;

struct node {
    int a[3], d;
    inline bool operator < (const node& o) const { return d > o.d; }
    node(int x,int y,int z,int _d):d(_d) { a[0]=x; a[1]=y; a[2]=z; }
    node(){}
}; //优先队列重载小于号需要加const
int vis[MAXN][MAXN], T, cap[3], goal, res, minc;

void bfs()
{
    res = minc = 0;
    memset(vis, 0, sizeof(vis));
    priority_queue<node> pq;
    pq.push(node(0, 0, cap[2], 0));
    vis[0][0] = 1;
    while (!pq.empty()) {
        node s = pq.top(); pq.pop();
        REP(i,3)if(s.a[i] <= goal && res < s.a[i]) { res = s.a[i]; minc = s.d; }
        if (res == goal) return;
        REP(i,3)REP(j,3)if(i!=j && s.a[i] && s.a[j]<cap[j]) {
            node t;
            if (s.a[i] <= cap[j]-s.a[j]) { t.a[i] = 0; t.a[j] = s.a[j]+s.a[i]; t.d = s.d+s.a[i]; }
            else { t.a[i] = s.a[i]-(cap[j]-s.a[j]); t.a[j] = cap[j]; t.d = s.d+(cap[j]-s.a[j]); }
            t.a[3-i-j] = s.a[3-i-j];
            if (!vis[t.a[0]][t.a[1]]) {
                vis[t.a[0]][t.a[1]] = 1;
                pq.push(t);
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

    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d", &cap[0], &cap[1], &cap[2], &goal);
        bfs();
        printf("%d %d\n", minc, res);
    }

    return 0;
}

































