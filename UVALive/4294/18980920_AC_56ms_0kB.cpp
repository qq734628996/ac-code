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
const int MAXN = 1e5+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int s,n,x[MAXN*3],cnt[MAXN],ok[MAXN*2];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &s,&n);
        fill(x,x+n+2*s,-1);
        REP(i,n) scanf("%d", &x[i+s]);
        int tot=0;
        fill(cnt+1,cnt+s+1,0);
        fill(ok,ok+n+s+1,0);
        REP(i,n+s+1) {
            if (tot==s) ok[i]=1;
            if (i<s && tot==i) ok[i]=1;
            if (i>n && tot==n+s-i) ok[i]=1;
            if (i==n+s) break;
            if (~x[i] && --cnt[x[i]]==0) tot--;
            if (~x[i+s] && cnt[x[i+s]]++==0) tot++;
        }
        int ans=0;
        REP(i,s) {
            bool vld=true;
            for (int j=i; j<=n+s; j+=s) vld&=ok[j];
            if (vld) ans++;
        }
        if (ans==n+1) ans=s;
        printf("%d\n", ans);
    }

    return 0;
}









































