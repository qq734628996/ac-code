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
const int MAXN  = 20, INF = ~0U>>1, MOD = ~0U>>1, EPS = 1e-8;


int n, m, k;
char G[MAXN][MAXN];
bool vis[256*256*256];

struct point {
    int x, y;
    void operator= (const point& o) { x = o.x; y = o.y; }
    bool operator<(const point& o) const { return x < o.x || (!(o.x < x) && y < o.y); }
    bool operator==(const point& o) const { return x == o.x && y == o.y; }
};
struct state {
    point p[3];
    int d;
    state(){}
    state(const state& o) { memcpy(&p, &o.p, sizeof(point)*k); d = o.d; }
    void operator= (const state& o) { memcpy(&p, &o.p, sizeof(point)*k); d = o.d; }
    bool operator < (const state& o) const {
        if (k == 1 || !(p[0] == o.p[0])) return p[0] < o.p[0];
        if (k == 2 || !(p[1] == o.p[1])) return p[1] < o.p[1];
        return p[2] < o.p[2];
    }
    bool operator == (const state& o) { return !memcmp(p, o.p, sizeof(point)*k); }
    bool valid(state& now) {
        REP(i,k)REP(j,k)if(i!=j && p[i]==p[j])return false;
        REP(i,k)REP(j,k)if(i!=j && p[i]==now.p[j] && p[j]==now.p[i]) return false;

        int id = 0;
        REP(i,k) {
            int num = p[i].x * n + p[i].y;
            REP(j,i) num *= 256;
            id += num;
        }
        if (vis[id]) return false;

        return true;
    }
    bool set_vis(bool flag) {
        int id = 0;
        REP(i,k) {
            int num = p[i].x * n + p[i].y;
            REP(j,i) num *= 256;
            id += num;
        }
        vis[id] = flag;
    }
} s, t;

vector<point> E[MAXN*MAXN];
queue<state> Q, visited;

void init()
{
    while (getchar() != '\n');
    REP(i,m) gets(G[i]);

    REP(i,m*n)E[i].clear();
    const int dx[] = {0,0,1,-1};
    const int dy[] = {1,-1,0,0};
    #define vld(x,y) (0<=x && x<=m && 0<=y && y<n && G[x][y]!='#')
    REP(i,m)REP(j,n) {
        if (islower(G[i][j])) s.p[G[i][j]-'a'] = (point){i,j};
        else if (isupper(G[i][j])) t.p[G[i][j]-'A'] = (point){i,j};

        if (G[i][j] != '#') REP(k,4) if (vld(i+dx[k], j+dy[k]))
            E[i*n + j].push_back((point){i+dx[k], j+dy[k]});
    }
/*
    REP(i,m*n){
        printf("(%d,%d) ", i/n, i%n);
        REP(j,SZ(E[i]))printf("(%d,%d)", E[i][j].x, E[i][j].y);
        puts("");
    }
*/
    REP(i,m)REP(j,n)E[i*n+j].push_back((point){i,j});

}

void pushNext(state& now, state& u, int cur)
{
    if (cur == k) {
        if (u.valid(now)) { Q.push(u), visited.push(u), u.set_vis(true); }
        return;
    }
    int nowid = now.p[cur].x * n + now.p[cur].y;
    REP(i,SZ(E[nowid])) {
        u.p[cur] = E[nowid][i];
        pushNext(now, u, cur+1);
    }
}

int bfs()
{
    while (!Q.empty()) Q.pop();
    s.d = 0;
    Q.push(s), visited.push(s), s.set_vis(true);
    while (!Q.empty()) {
        state now = Q.front(); Q.pop();
            //REP(i,k)printf("(%d,%d),", now.p[i].x, now.p[i].y);
            //printf("d=%d\n", now.d);
        if (now == t) {
            for ( ; !visited.empty(); visited.pop()) visited.front().set_vis(false);
            return now.d;
        }
        state u;
        u.d = now.d + 1;
        pushNext(now, u, 0);
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d%d", &n, &m, &k), n) {
        init();
        printf("%d\n", bfs());
    }

    return 0;
}

































