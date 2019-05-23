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

int n,m,h[11][11],v[11][11],kase;
int jdg(int x, int y, int len)
{
    REP(k,len) if (!h[x][y+k] || !h[x+len][y+k] || !v[x+k][y] || !v[x+k][y+len]) return 0;
    return 1;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d", &n,&m)==2) {
        if (kase++) printf("\n**********************************\n\n");
        printf("Problem #%d\n\n", kase);
        memset(h,0,sizeof(h));
        memset(v,0,sizeof(v));
        REP(i,m) {
            char s[10];
            int x,y;
            scanf("%s%d%d", s,&x,&y);
            if (s[0]=='H') h[x][y]=1;
            else v[y][x]=1;
        }
        bool fail=true;
        FOR(len,1,n-1) {
            int cnt=0;
            FOR(i,1,n-len)FOR(j,1,n-len) cnt+=jdg(i,j,len);
            if (cnt) {
                printf("%d square (s) of size %d\n", cnt,len);
                fail=false;
            }
        }
        if (fail) puts("No completed squares can be found.");
    }

    return 0;
}













































