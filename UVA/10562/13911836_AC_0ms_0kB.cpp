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
const int MAXN  = 2e2+5, INF = ~0U>>1, MOD = ~0U>>1;

int T, n;
char buf[MAXN][MAXN];
void dfs(int i, int l, int r)
{
    int len = strlen(buf[i]);
    FOR(j,l,r)if(j<len && !isspace(buf[i][j])) {
        printf("%c(", buf[i][j]);
        if (i+1<n && buf[i+1][j]=='|') {
            int nl = j, nr = j;
            while (0<=--nl && buf[i+2][nl]=='-');
            while (buf[i+2][++nr]!='\0' && buf[i+2][nr]=='-');
            dfs(i+3,nl+1,nr-1);
        }
        putchar(')');
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T); getchar();
    while (T--) {
        n = -1;
        while (gets(buf[++n]), buf[n][0] != '#');
        putchar('(');
        if (n) dfs(0,0,strlen(buf[0])-1);
        puts(")");
    }





    return 0;
}






















