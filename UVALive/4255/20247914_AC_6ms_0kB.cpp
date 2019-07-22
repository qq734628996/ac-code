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
const int MAXN = 2e3+9, MAXM = 1e4+5;

int n,g[22][22],in[22],B[22];
char s[222];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%s", &n,s);
        int len=0;
        FOR(i,0,n)FOR(j,0,n)if (j>i) {
            if (s[len]=='0') g[i][j]=0;
            else g[i][j]=s[len]=='-'?-1:1;
            len++;
        }
        FOR(i,0,n)FOR(j,0,n)if (j<i) g[i][j]=-g[j][i];
        memset(in,0,sizeof(in));
        FOR(i,0,n)FOR(j,0,n)if (g[i][j]<0) in[i]++;
        queue<pii> Q;
        FOR(i,0,n) if (!in[i]) Q.push({i,0});
        while (!Q.empty()) {
            pii now=Q.front(); Q.pop();
            int u=now.fi, cnt=now.se;
            B[u]=cnt;
            FOR(v,0,n) if (v!=u) {
                if (g[u][v]==0) B[v]=B[u];
                else if (g[u][v]) {
                    if (--in[v]==0) Q.push({v,cnt+1});
                }
            }
        }
        FOR(i,1,n) B[i]-=B[0];
        B[0]=0;
        FOR(i,1,n) printf("%d%c", B[i]-B[i-1],i==n?'\n':' ');
    }

    return 0;
}


































