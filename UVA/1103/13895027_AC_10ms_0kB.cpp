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

const char he[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
const char* de[] = {"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
const char ans[] = {'W','A','K','J','S','D'};
const int dir[][2] = {{0,1},{0,-1},{1,0},{-1,0}};

int m, n, cnt, kase;
char s[MAXN], a[MAXN][MAXN], res[MAXN]; //1或-2（已访问）表示图像上的点，0或-1（已访问）表示图像外围的点，2及以上表示连通域所属编号
#define vld(x,y) (0<=x && x<m && 0<=y && y<4*n)

void dfs1(int r, int c, int num)
{
    if (!vld(r, c) || a[r][c]) return;
    a[r][c] = num;
    REP(i,4) dfs1(r+dir[i][0], c+dir[i][1], num);
}

void dfs2(int r, int c)
{
    a[r][c] = -2;
    REP(k,4) {
        int i = r+dir[k][0], j = c+dir[k][1];
        if (vld(i,j)) {
            if (a[i][j] == 1) dfs2(i,j);
            else if (!a[i][j]) { cnt++; dfs1(i,j,cnt+1); }
        }
    }
}


int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL


    while (scanf("%d%d", &m, &n), m) {
        REP(i,m) {
            scanf("%s", s);
            REP(j,n) {
                int k = 0;
                for ( ; s[j] != he[k]; k++);
                REP(l,4)a[i][j*4+l] = de[k][l] - '0';
            }
        }
/*
        REP(i,m) {
            REP(j,n*4){
                if (a[i][j]) printf("●");
                else printf("○");
            }
            puts("");
        }
*/

        int jlen = n<<2, idx = 0;

        REP(i,m) //从四个边界开始遍历图像外围的点
            if (!a[i][0]) dfs1(i, 0, -1);
            else if (!a[i][jlen-1]) dfs1(i, jlen-1, -1);
        REP(j,jlen)
            if (!a[0][j]) dfs1(0, j, -1);
            else if (!a[m-1][j]) dfs1(m-1, j, -1);

        REP(i,m)REP(j,jlen) {
            if (a[i][j] == 1) {
                cnt = 0;
                dfs2(i,j);
                res[idx++] = ans[cnt];
            }
        }
        res[idx] = '\0';
        sort(res,res+idx);
        printf("Case %d: %s\n", ++kase, res);



    }







    return 0;
}
