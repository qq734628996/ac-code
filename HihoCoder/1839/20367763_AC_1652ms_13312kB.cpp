#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n) printf("%d%c", A[i],i==n-1?'\n':' '); }
#define SHOW2(A,m,n) { REP(j,m) SHOW1(A[j],n) }
#define pb push_back
#define fi first
#define se second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)((x).size())
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const int INF = 0x3f3f3f3f, MOD = 1000000007;
const double PI = acos(-1), EPS = 1e-15;
const int MAXN = 5e6+9, MAXM = 3e3+9;

char s[MAXN];
bool vis[MAXN];
int prime[MAXN/10],tot;
void getPrime(int n)
{
    FOR(i,2,n) {
        if (!vis[i]) prime[tot++]=i;
        REP(j,tot) {
            if (i*prime[j]>n) break;
            vis[i*prime[j]]=1;
            if (i%prime[j]==0) break;
        }
    }
}
LL powMod(LL x, LL e, LL mod)
{
    if (!e) return 1;
    return e&1 ? powMod(x,e-1,mod)*x%mod : powMod(x*x%mod,e>>1,mod);
}

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    getPrime(MAXN-1);
    scanf("%s",s);
    int sum=0;
    int len=strlen(s);
    REP(i,len) sum+=s[i]-'0';
    REP(i,tot) {
        LL mod=prime[i]*9;
        LL res=powMod(10,len,mod);
        res=(res-1+mod)%mod/9;
        if ((res*sum)%prime[i]==0) {
            printf("%d\n", prime[i]);
            break;
        }
    }

    return 0;
}

































