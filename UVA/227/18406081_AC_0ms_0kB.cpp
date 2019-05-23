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

char a[10][10],ch;
int kase,x,y;
#define vld(i,j) (0<=i&&i<5&&0<=j&&j<5)
const char* dir="ABLR";
const int r[]={-1,1,0,0};
const int c[]={0,0,-1,1};

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (fgets(a[0],MAXN,stdin), a[0][0]!='Z') {
        if (kase++) puts("");
        printf("Puzzle #%d:\n", kase);
        FOR(i,1,4) fgets(a[i],MAXN,stdin);
        REP(i,5)REP(j,5) if (a[i][j]==' ') x=i, y=j;
        bool flag=true;
        while ((ch=getchar()) != '0') if (ch!='\n') {
            int i=strchr(dir,ch)-dir;
            if (i<0||i>3) { flag=false; continue; }
            int xx=x+r[i], yy=y+c[i];
            if (!vld(xx,yy)) flag=false;
            if (flag) {
                a[x][y]=a[xx][yy];
                a[xx][yy]=' ';
                x=xx, y=yy;
            }
        }
        while (getchar()!='\n');
        if (!flag) puts("This puzzle has no final configuration.");
        else {
            REP(i,5) {
                REP(j,4) printf("%c ", a[i][j]);
                printf("%c\n", a[i][4]);
            }
        }
    }

    return 0;
}














































