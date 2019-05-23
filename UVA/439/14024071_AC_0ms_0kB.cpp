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
const int MAXN  = 2e3+5, INF = ~0U>>1, MOD = ~0U>>1;

const int dr[8][2] = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
#define vld(x,y) (0<=x && x<8 && 0<=y && y<8)
char s1[3], s2[3];
int G[8][8];
struct point {
    int x, y;
    bool operator == (const point& p) { return (x == p.x && y == p.y); }
};
void bfs()
{
    memset(G, -1, sizeof(G));
    point st{s1[0]-'a', s1[1]-'1'}, ed{s2[0]-'a', s2[1]-'1'};
    queue<point> Q;
    Q.push(st); G[st.x][st.y] = 0;
    for ( ; ; Q.pop()) {
        point& p = Q.front();
        if (p == ed) {
            printf("To get from %s to %s takes %d knight moves.\n", s1, s2, G[p.x][p.y]);
            return;
        }
        REP(k,8) {
            int i = p.x + dr[k][0], j = p.y + dr[k][1];
            if (vld(i,j) && G[i][j] == -1) {
                G[i][j] = G[p.x][p.y] + 1;
                Q.push((point){i,j});
            }
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%s%s", s1, s2)) bfs();

    return 0;
}






















