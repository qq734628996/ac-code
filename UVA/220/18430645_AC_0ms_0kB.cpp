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
const int MAXN = 1e3+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int a[11][11],now;
const int r[]={0,1,1,1,0,-1,-1,-1};
const int c[]={1,1,0,-1,-1,-1,0,1};
#define vld(i,j) (1<=i&&i<=8&&1<=j&&j<=8)
bool jdg(int x, int y, int k)
{
    if (a[x][y]!=-1) return false;
    int xx=x,yy=y,cnt=0;
    while (xx+=r[k],yy+=c[k], vld(xx,yy) && a[xx][yy]==!now) cnt++;
    return cnt && vld(xx,yy) && a[xx][yy]==now;
}
vector<pii> List()
{
    vector<pii> V;
    FOR(i,1,8)FOR(j,1,8)REP(k,8) if (jdg(i,j,k)) {
        V.pb(pii(i,j));
        break;
    }
    return V;
}
void Move(int x, int y)
{
    vector<pii> V=List();
    if (find(ALL(V),pii(x,y))==V.end()) now=!now;
    REP(k,8) if (jdg(x,y,k)) {
        int xx=x,yy=y;
        while (xx+=r[k],yy+=c[k], vld(xx,yy) && a[xx][yy]==!now) a[xx][yy]=now;
    }
    a[x][y]=now;
    now=!now;
    int cnt[2]={0};
    FOR(i,1,8)FOR(j,1,8)if (~a[i][j]) cnt[a[i][j]]++;
    printf("Black - %2d White - %2d\n", cnt[1],cnt[0]);
}
void show()
{
    FOR(i,1,8) {
        FOR(j,1,8) {
            if (~a[i][j]) putchar(a[i][j] ? 'B':'W');
            else putchar('-');
        }
        puts("");
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    REP(kase,T) {
        if (kase) puts("");
        char buf[12];
        FOR(i,1,8) {
            scanf("%s", buf+1);
            FOR(j,1,8) {
                if (buf[j]=='-') a[i][j]=-1;
                else a[i][j]=buf[j]=='B';
            }
        }
        scanf("%s", buf);
        now=buf[0]=='B';
        char op[11];
        while (scanf("%s", op), op[0]!='Q') {
            if (op[0]=='L') {
                vector<pii> V=List();
                if (!SZ(V)) puts("No legal move.");
                else {
                    int cnt=0;
                    for (auto& i:V) {
                        if (cnt++) printf(" ");
                        printf("(%d,%d)", i.fi,i.se);
                    }
                    puts("");
                }
            } else Move(op[1]-'0',op[2]-'0');
        }
        show();
    }

    return 0;
}













































