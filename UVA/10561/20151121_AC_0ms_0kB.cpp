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
const int INF = 0x3f3f3f3f, MOD = 100000007;
const int MAXN = 2e2+9, MAXM = 1e4+5;

char s[MAXN];
int ans[MAXN],tot,g[MAXN],vis[MAXN];
int SG(int l, int r)
{
    if (r<l) return 0;
    FOR(i,l,r) if (s[i]=='X') return SG(l,i-3) ^ SG(i+3,r);
    return g[r-l+1];
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    FOR(i,1,3) g[i]=1;
    FOR(i,4,200) {
        REP(j,i) vis[g[max(0,j-2)]^g[max(0,i-3-j)]]=i;
        FOR(j,0,200) if (vis[j]!=i) {
            g[i]=j;
            break;
        }
    }
    int T; scanf("%d", &T);
    while (T--) {
        tot=0;
        scanf("%s", s);
        int n=strlen(s);
        if (strstr(s,"XX") || strstr(s,"X.X")) {
            puts("WINNING");
            REP(i,n) if (s[i]=='.') {
                if ((i-2>=0 && s[i-2]=='X' && s[i-1]=='X') ||
                    (i+2<n && s[i+1]=='X' && s[i+2]=='X') ||
                    (i-1>=0 && i+1<n && s[i-1]=='X' && s[i+1]=='X')) {
                        ans[tot++]=i+1;
                }
            }
            SHOW1(ans,tot)
            continue;
        }
        if (SG(0,n-1)) {
            puts("WINNING");
            REP(i,n) if (s[i]=='.') {
                s[i]='X';
                if (!strstr(s,"XX") && !strstr(s,"X.X") && !SG(0,n-1)) ans[tot++]=i+1;
                s[i]='.';
            }
            SHOW1(ans,tot)
        } else puts("LOSING\n");
    }

    return 0;
}




































