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
const int MAXN  = 4e3+5, INF = ~0U>>1, MOD = ~0U>>1;


const char* dr = "ESWN";
const char* dir = "FR L";
const int go[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
#define dr_id(x) (strchr(dr,x)-dr)
#define dir_id(x) (strchr(dir,x)-dir)

char name[25], buf[10], ch;
int x, y, si, sj, beg, ei, ej, ed, edge[10][10][4][4];

struct node {
    int x, y, in;
    node(){}
    node(int _x, int _y, int _in) : x(_x), y(_y), in(_in) {}
}*tmp, p[10][10][4];

bool bfs()
{
    queue<node> q;
    q.push(node(si+go[beg][0], sj+go[beg][1], beg));
    p[si+go[beg][0]][sj+go[beg][1]][beg] = node(si, sj, -1);
    for ( ; !q.empty(); q.pop()) {
        tmp = &q.front();
            //printf("(%d,%d)\n", tmp->x, tmp->y);
        if (tmp->x == ei && tmp->y == ej) { ed = tmp->in; return true; }
        REP(i,4) if (edge[tmp->x][tmp->y][tmp->in][i]) {
            int ti = tmp->x + go[i][0], tj = tmp->y + go[i][1];
            if (!p[ti][tj][i].x) {
                q.push(node(ti, tj, i));
                p[ti][tj][i] = *tmp;
            }
        }
    }
    return false;
}

void print_ans()
{
    stack<node> s;
    s.push(node(ei, ej, ed));
    while (!(s.top().x == si && s.top().y == sj && s.top().in == -1)) {
            //printf("(%d,%d)\n", s.top().x, s.top().y);
        s.push(p[s.top().x][s.top().y][s.top().in]);
    }
    for (int i = 0; !s.empty(); s.pop()) {
        if (i++ % 10 == 0) printf("\n ");
        printf(" (%d,%d)", s.top().x, s.top().y);
    }
    puts("");
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%s", name), strcmp(name, "END")) {
        printf("%s", name);
        memset(edge, 0, sizeof(edge));
        memset(p, 0, sizeof(p));
        scanf("%d%d %c %d%d", &si, &sj, &ch, &ei, &ej);
        beg = dr_id(ch);
        while (scanf("%d", &x), x) {
            scanf("%d", &y);
            while (scanf("%s", buf), buf[0] != '*') {
                int idx = dr_id(buf[0]), len = strlen(buf);
                FOR(i,1,len-1) edge[x][y][idx][ (idx+dir_id(buf[i]))%4 ] = 1;
            }
        }
        if (bfs()) print_ans();
        else puts("\n  No Solution Possible");
    }








    return 0;
}
