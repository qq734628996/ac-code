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
const int INF = 0x3f3f3f3f, MOD = 1000000;
const double EPS = 1e-14;
const int MAXN = 1e3+9, MAXM = 1e4+5;

char s[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    FOR(kase,1,T) {
        scanf("%s", s);
        int len=strlen(s);
        int cnt=0,sum=0;
        REP(i,len) {
            sum+=s[i]-'0';
            if ((s[i]-'0')%3==0) cnt++;
        }
        bool win=false;
        if (sum%3==0) {
            win=(cnt&1);
        } else if (cnt%2==0) {
            REP(i,len) if ((s[i]-'0')%3==sum%3) win=true;
        }
        printf("Case %d: %c\n", kase,win?'S':'T');
    }

    return 0;
}




































