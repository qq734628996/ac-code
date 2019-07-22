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
const int MAXN = 1e3+9, MAXM = 5e3+5, INF = 0x3f3f3f3f, MOD = 1000000000;

LL powMod(LL x, LL e, LL p)
{
    if (!e) return 1;
    return e&1 ? powMod(x,e-1,p)*x%p : powMod(x*x%p,e>>1,p);
}
char s[MAXN];
LL C[MAXN],k,mo;
void parse()
{
    memset(C,0,sizeof(C));
    int sgn=1, c=1, e=0, flag=0;
    char* p;
    k=0;
    for (p=s+1;; p++) {
        if (*p=='n') e=1, flag=1;
        else if (*p=='+' || *p=='-' || *p==')') {
            if (p==s+1) { sgn=-1; continue; }
            C[e]=sgn*c;
            k=max(k,(LL)e);
            if (*p==')') break;
            sgn=*p=='+'?1:-1;
            c=1;
            e=0;
            flag=0;
        } else if (isdigit(*p)) {
            if (!flag) sscanf(p,"%d",&c);
            else sscanf(p,"%d",&e);
            while (isdigit(*(p+1))) p++;
        }
    }
    while (!isdigit(*p)) p++;
    sscanf(p,"%lld",&mo);
}
bool jdg(int x)
{
    LL ans=0;
    FOR(e,0,k) if (C[e]) {
        ans+=C[e]*powMod(x,e,mo);
        ans%=mo;
    }
    return ans==0;
}
bool solve()
{
    FOR(i,1,k+1) if (!jdg(i)) return false;
    return true;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int kase=0;
    while (scanf("%s", s)==1 && s[0]!='.') {
        parse();
        printf("Case %d: %s an integer\n", ++kase,solve()?"Always":"Not always");
    }

    return 0;
}




































