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
typedef pair<int, int> pii;
const int MAXN = 1e2+5, MAXM = 5e3+5, INF = 0x3f3f3f3f, MOD = 10007;

int n,m,u[MAXN],v[MAXN],g[MAXN][MAXN];
int ind[1<<15],d[1<<15],pre[1<<15],color[15];
bool independent(int mask)
{
    REP(i,15) if (mask>>i&1) {
        REP(j,15) if (mask>>j&1) {
            if (i!=j && g[i][j]) return false;
        }
    }
    return true;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &m)==1) {
        memset(g,0,sizeof(g));
        int nodes=0;
        REP(i,m) {
            char s[11],t[11];
            scanf("%s%s", s,t);
            u[i]=s[0]-'L', v[i]=t[0]-'L';
            g[u[i]][v[i]]=g[v[i]][u[i]]=1;
            nodes|=(1<<u[i]);
            nodes|=(1<<v[i]);
        }
        for (int i=nodes; i; i=(i-1)&nodes) {
            ind[i]=independent(i);
        }
        FOR(i,1,nodes) if ((nodes|i)==nodes) {
            d[i]=INF;
            for (int j=i; j; j=(j-1)&i) if (ind[j]) {
                if (d[i]>d[i^j]+1) {
                    d[i]=d[i^j]+1;
                    pre[i]=(i^j);
                }
            }
        }
        for (int i=nodes, c=0; i; i=pre[i], c++) {
            REP(j,15) if (i>>j&1) color[j]=c;
        }
        printf("%d\n", d[nodes]-2);
        REP(i,m) {
            if (color[u[i]]<color[v[i]]) swap(u[i],v[i]);
            printf("%c %c\n", 'L'+u[i],'L'+v[i]);
        }
    }

    return 0;
}





































