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
const int MAXN = 1e6+9, MAXM = 2e6+5, INF = 0x3f3f3f3f, MOD = 1000000000;

void ex_gcd(LL a, LL b, LL& d, LL& x, LL& y)
{
    if (!b) x=1, y=0, d=a;
    else ex_gcd(b,a%b,d,y,x), y-=x*(a/b);
}
LL china(int* a, int* m, int n)
{
    LL M=1,d,y,x=0;
    REP(i,n) M*=m[i];
    REP(i,n) {
        LL w=M/m[i];
        ex_gcd(m[i],w,d,d,y);
        x=(x+y*w*a[i])%M;
    }
    return (x+M)%M;
}
const int maxc=9, maxk=100, LIMIT=10000;
set<int> values[maxc];
int C,X[maxc],k[maxc],Y[maxc][maxk];
void solve_enum(int S, int bc)
{
    REP(c,C) if (c!=bc) {
        values[c].clear();
        REP(i,k[c]) values[c].insert(Y[c][i]);
    }
    for (int t=0; S; t++) {
        REP(i,k[bc]) {
            LL n=(LL)X[bc]*t+Y[bc][i];
            if (!n) continue;
            bool ok=true;
            REP(c,C) if (c!=bc && !values[c].count(n%X[c])) {
                ok=false;
                break;
            }
            if (ok) {
                printf("%lld\n", n);
                if (--S==0) break;
            }
        }
    }
}
int a[maxc];
vector<LL> sol;
void dfs(int dep)
{
    if (dep==C) sol.push_back(china(a,X,C));
    else REP(i,k[dep]) {
        a[dep]=Y[dep][i];
        dfs(dep+1);
    }
}
void solve_china(int S)
{
    sol.clear();
    dfs(0);
    sort(ALL(sol));
    LL M=1;
    REP(i,C) M*=X[i];
    vector<LL> ans;
    for (int i=0; S; i++) {
        REP(j,SZ(sol)) {
            LL n=M*i+sol[j];
            if (n<=0) continue;
            printf("%lld\n", n);
            if (--S==0) break;
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int S;
    while (scanf("%d%d", &C,&S)==2 && C) {
        LL tot=1;
        int bestc=0;
        REP(c,C) {
            scanf("%d%d", &X[c],&k[c]);
            tot*=k[c];
            REP(i,k[c]) scanf("%d", &Y[c][i]);
            sort(Y[c],Y[c]+k[c]);
            if (k[c]*X[bestc]<k[bestc]*X[c]) bestc=c;
        }
        if (tot>LIMIT) solve_enum(S,bestc);
        else solve_china(S);
        puts("");
    }

    return 0;
}




































