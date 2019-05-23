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
typedef pair<int, int> pii;
const int MAXN  = 53, INF = ~0U>>1, MOD = ~0U>>1;

int T, n ,k, a[MAXN<<1][MAXN<<1], vis[MAXN<<1][MAXN<<1], cnt;
char ans[MAXN];
const char dir[] = { 'e', 'n', 's', 'w' };
const int r[] = { 1, 0, 0,-1 }; //注意坐标是反的
const int c[] = { 0, 1,-1, 0 };

void dfs(int now, pii p)
{
    if (now == n+1) {
        if (!p.first && !p.second) { puts(ans+1); cnt++; }
        return;
    }
    REP(i,4) {
        if (now > 1 && (((i==0||i==3) && (ans[now-1]=='e'||ans[now-1]=='w')) || ((i==1||i==2) && (ans[now-1]=='n'||ans[now-1]=='s')))) continue;
        int newi = p.first+r[i]*now, newj = p.second+c[i]*now;
        if (abs(newi)>=MAXN || abs(newj)>=MAXN) continue;
        if (vis[newi+MAXN][newj+MAXN] || (!newi && !newj && now!=n)) continue;

        bool flag = true;
        FOR(k,1,now) if (a[p.first+r[i]*k+MAXN][p.second+c[i]*k+MAXN]) flag = false;
        if (flag) {
            ans[now] = dir[i];
            vis[newi+MAXN][newj+MAXN] = 1;
            dfs(now+1, pii(newi, newj));
            vis[newi+MAXN][newj+MAXN] = 0;
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
        scanf("%d%d", &n, &k);
        memset(a, 0, sizeof(a));
        REP(i,k) {
            int x, y; scanf("%d%d", &x, &y);
            if (abs(x)<MAXN && abs(y)<MAXN) a[x+MAXN][y+MAXN] = 1;
        }
        ans[n+1] = '\0';
        cnt = 0;
        dfs(1, pii(0, 0));
        printf("Found %d golygon(s).\n\n", cnt);
    }

    return 0;
}















































































