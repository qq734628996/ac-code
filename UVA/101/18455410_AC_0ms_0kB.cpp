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
const int MAXN = 1e4+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n,p[33],a,b;
char op1[11],op2[11];
vector<int> V[33];
void clr(int x)
{
    PER(i,SZ(V[p[x]])) {
        int r=V[p[x]][i];
        if (r==x) break;
        V[p[x]].pop_back();
        V[r].pb(r);
        p[r]=r;
    }
}
void show()
{
    REP(i,n) {
        printf("%d:", i);
        REP(j,SZ(V[i])) printf(" %d", V[i][j]);
        puts("");
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &n);
    REP(i,n) p[i]=i, V[i].pb(i);
    while (scanf("%s%d%s%d", op1,&a,op2,&b)==4 && op1[0]!='q') {
        if (p[a]!=p[b]) {
            if (op1[0]=='m') clr(a);
            if (op2[1]=='n') clr(b);
            int pos=find(ALL(V[p[a]]),a)-V[p[a]].begin();
            int pa=p[a];
            for (int i=pos; i<SZ(V[pa]); i++) {
                int r=V[pa][i];
                V[p[b]].pb(r);
                p[r]=p[b];
            }
            V[pa].resize(pos);
        }
    }
    show();

    return 0;
}












































