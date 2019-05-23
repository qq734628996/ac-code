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
const int MAXN = 1e2+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n,a[33];
char buf[1234];
map<int,int> mp;
int bits(int x) { return x ? bits(x>>1)+(x&1) : 0; }

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d", &n)) {
        memset(a,0,sizeof(a));
        REP(i,n) {
            scanf("%s", buf);
            int len=strlen(buf);
            REP(j,len) a[i]^=(1<<(buf[j]-'A'));
        }
        mp.clear();
        int n1=n/2, n2=n-n1;
        REP(i,(1<<n1)) {
            int x=0;
            REP(j,n1) if (i&(1<<j)) x^=a[j];
            if (!mp.count(x) || bits(mp[x])<bits(i)) mp[x]=i;
        }
        int ans=0;
        REP(i,(1<<n2)) {
            int x=0;
            REP(j,n2) if (i&(1<<j)) x^=a[n1+j];
            if (mp.count(x) && bits(ans)<bits(mp[x])+bits(i)) ans=(i<<n1)^mp[x];
        }
        printf("%d\n", bits(ans));
        REP(i,n) if (ans&(1<<i)) printf("%d ", i+1);
        puts("");
    }

    return 0;
}










































