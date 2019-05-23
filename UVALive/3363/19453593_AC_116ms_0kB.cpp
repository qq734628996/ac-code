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
const int MAXN = 2e2+5, MAXM = 5e3+5, INF = 0x3f3f3f3f, MOD = 10007;

char s[MAXN];
int n,d[MAXN][MAXN];
string ans[MAXN][MAXN];
bool jdg(int i, int k, int j)
{
    FOR(t,i,j) if (s[t]!=s[i+(t-i)%k]) return false;
    return true;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%s", s+1);
        n=strlen(s+1);
        FOR(i,1,n) d[i][i]=1, ans[i][i].clear(), ans[i][i].pb(s[i]);
        FOR(len,1,n)FOR(i,1,n-len) {
            int j=i+len;
            d[i][j]=INF;
            FOR(k,i,j-1) {
                if (d[i][j]>d[i][k]+d[k+1][j]) {
                    d[i][j]=d[i][k]+d[k+1][j];
                    ans[i][j]=ans[i][k]+ans[k+1][j];
                }
            }
            FOR(k,1,len) if ((len+1)%k==0 && jdg(i,k,j)) {
                int cnt=(j-i+1)/k;
                int nlen=2+d[i][i+k-1];
                for (int x=cnt; x; x/=10) {
                    nlen++;
                }
                if (d[i][j]>nlen) {
                    d[i][j]=nlen;
                    char buf[10];
                    sprintf(buf,"%d",cnt);
                    ans[i][j]=string(buf)+"("+ans[i][i+k-1]+")";
                }
            }
        }
        cout<<ans[1][n].size()<<endl;
    }

    return 0;
}






































