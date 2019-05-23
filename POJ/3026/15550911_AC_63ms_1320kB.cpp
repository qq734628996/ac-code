#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>

#include <iostream>
#include <algorithm>
//#include <unordered_map>
//#include <unordered_set>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
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
const int MAXN = 1e3+5, MAXM = 1e6+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n, m, u[MAXM], v[MAXM], w[MAXM], r[MAXM], p[MAXN];
bool cmp(const int i, const int j) { return w[i] < w[j]; }
int Find(int x) { return p[x] == x ? x : p[x] = Find(p[x]); }
bool Union(int i, int j) { int x = Find(i), y = Find(j); if (x != y) p[x] = y; return x != y; }
int Kruskal()
{
    REP(i,m) r[i] = i;
    sort(r, r+m, cmp);
    FOR(i,1,n) p[i] = i;
    int ans = 0;
    REP(i,m) {
        int e = r[i];
        if (Union(u[e], v[e])) ans += w[e];
    }
    return ans;
}

char s[MAXN][MAXN];
int a, b, x[MAXN], y[MAXN], id[MAXN][MAXN], vis[MAXN][MAXN];
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
struct node {
    int x, y, d;
};
inline bool vld(int i, int j) { return 0<=i && i<a && 0<=j && j<b; }

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &b, &a);
        while (getchar() != '\n');
        REP(i,a) {
            REP(j,b) s[i][j] = getchar();
            getchar();
        }
        n = 0;
        REP(i,a)REP(j,b) id[i][j] = 0;
        REP(i,a)REP(j,b) {
            if (s[i][j] == 'S' || s[i][j] == 'A') {
                id[i][j] = ++n;
                x[n] = i; y[n] = j;
            }
        }
        m = 0;
        FOR(i,1,n) {
            queue<node> Q;
            REP(i,a)REP(j,b) vis[i][j] = 0;
            Q.push((node){x[i],y[i],0});
            vis[x[i]][y[i]] = 1;
            while (!Q.empty()) {
                node now = Q.front(); Q.pop();
                REP(j,4) {
                    int xx = now.x+dr[j], yy = now.y+dc[j];
                    if (vld(xx,yy) && !vis[xx][yy] && s[xx][yy] != '#') {
                        vis[xx][yy] = 1;
                        Q.push((node){xx,yy,now.d+1});
                        if (s[xx][yy] != ' ') {
                            u[m] = i; v[m] = id[xx][yy];
                            w[m++] = now.d+1;
                        }
                    }
                }
            }
        }
        //REP(i,m) printf("---%d %d %d\n", u[i], v[i], w[i]);
        printf("%d\n", Kruskal());
    }

    return 0;
}


















































































