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
const int MAXN  = 1e2+5, INF = ~0U>>1, MOD = ~0U>>1;




int G[MAXN][MAXN], in[MAXN], n, m, a, b;
void topoSort(vector<int>& res)
{
    queue<int> q; int t;
    FOR(i,1,n)if(!in[i])q.push(i);
    while (!q.empty()) {
        t = q.front(); q.pop(); res.push_back(t);
        FOR(i,1,n)if(G[t][i]) {
            in[i]--;
            if (!in[i]) q.push(i);
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d", &n, &m), n) {
        memset(G, 0, sizeof(G));
        memset(in, 0, sizeof(in));
        REP(i,m) {
            scanf("%d%d", &a, &b);
            if(!G[a][b]) {
                G[a][b] = 1;
                in[b]++;
            }
        }
        //SHOW2(G,n+1,n+1)
        //SHOW1(in,n+1)
        vector<int> v;
        topoSort(v);
        if (SZ(v) == n) {
            REP(i,n) {
                if (i) putchar(' ');
                printf("%d", v[i]);
            }
            puts("");
        }
    }








    return 0;
}






















