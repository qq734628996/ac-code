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

int n,gx,gy,x[11],y[11];
char s[11][11];
const int r[]={0,0,1,-1};
const int c[]={1,-1,0,0};
const int rr[]={1,-1,1,-1,2,2,-2,-2};
const int cc[]={2,2,-2,-2,1,-1,1,-1};
#define vld(i,j) (1<=i&&i<=10&&1<=j&&j<=9)
#define gvld(i,j) (1<=i&&i<=3&&4<=j&&j<=6)

int cnt1(int yy, int x1, int x2)
{
    int cnt=0;
    REP(i,n) if (y[i]==yy && min(x1,x2)<x[i] && x[i]<max(x1,x2)) cnt++;
    return cnt;
}
int cnt2(int xx, int y1, int y2)
{
    int cnt=0;
    REP(i,n) if (x[i]==xx && min(y1,y2)<y[i] && y[i]<max(y1,y2)) cnt++;
    return cnt;
}
bool valid(int ni, int nj)
{
    int xx,yy,cnt;
    REP(i,n) switch (s[i][0]) {
        case 'R':
            if (ni==x[i] && nj!=y[i] && !cnt2(ni,nj,y[i])) return false;
            if (nj==y[i] && ni!=x[i] && !cnt1(nj,ni,x[i])) return false;
            break;
        case 'G':
            if (nj==y[i] && !cnt1(nj,ni,x[i])) return false;
            break;
        case 'H':
            REP(j,4) {
                xx=x[i]+r[j];
                yy=y[i]+c[j];
                if (vld(xx,yy)) {
                    cnt=0;
                    REP(k,n) if (xx==x[k] && yy==y[k]) cnt++;
                    if (!cnt) {
                        REP(k,2) if (ni==x[i]+rr[j*2+k] && nj==y[i]+cc[j*2+k])
                            return false;
                    }
                }
            }
            break;
        case 'C':
            if (ni==x[i] && cnt2(ni,nj,y[i])==1) return false;
            if (nj==y[i] && cnt1(nj,ni,x[i])==1) return false;
            break;
    }
    return true;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d%d", &n,&gx,&gy)==3 && n) {
        REP(i,n) scanf("%s%d%d", s[i],&x[i],&y[i]);
        bool flag=false;
        REP(i,4) {
            int xx=gx+r[i], yy=gy+c[i];
            if (gvld(xx,yy)) flag |= valid(xx,yy);
        }
        REP(i,n) if (s[i][0]=='G' && gy==y[i] && !cnt1(gy,gx,x[i])) flag=true;
        puts(!flag ? "YES" : "NO");
    }

    return 0;
}














































