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
const int MAXN = 1e6+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int m,n;
char s[123][123];
#define vld(i,j) (0<=i&&i<m&&0<=j&&j<n)
bool jdg(int i, int j)
{
    int r=1, c=1;
    char ch=s[i][j];
    while (vld(i+r,j) && s[i+r][j]==ch && vld(i+r,j+1) && s[i+r][j+1]=='.') r++;
    while (vld(i,j+c) && s[i][j+c]==ch && vld(i+1,j+c) && s[i+1][j+c]=='.') c++;
    if (r<2 || c<2) return false;
    FOR(x,0,r)FOR(y,0,c) {
        int xx=i+x, yy=j+y;
        char now=((!x || !y || x==r || y==c) ? ch:'.');
        if (s[xx][yy] != now) return false;
    }
    return true;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d", &m,&n)==2 && m) {
        REP(i,m) scanf("%s", s[i]);
        set<char> S;
        REP(i,m)REP(j,n) if (s[i][j]!='.' && jdg(i,j)) S.insert(s[i][j]);
        for (auto& i:S) putchar(i);
        puts("");
    }

    return 0;
}









































