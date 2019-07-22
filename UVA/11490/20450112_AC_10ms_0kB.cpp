#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n) cout<<A[i]<<(i==n-1?'\n':' '); }
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
const int INF = 0x3f3f3f3f, MOD = 100000007;
const double PI = acos(-1), EPS = 1e-15;
const int MAXN = 1e6+9, MAXM = 3e3+9;

bool vis[MAXN];
LL prime[MAXN/10],tot;
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
vector<pll> e;
void gete(LL n)
{
    e.clear();
    REP(i,tot) {
        if (prime[i]*prime[i]>n) break;
        int cnt=0;
        while (n%prime[i]==0) {
            n/=prime[i];
            cnt++;
        }
        if (cnt) e.pb({prime[i],cnt});
    }
    if (n!=1) e.pb({n,1});
}
LL n;
set<LL> ans;
void dfs(int i, LL now)
{
    if (i==SZ(e)) {
        LL t=8*now+n/now;
        if (t%7) return;
        LL c=t/7;
        LL r=2*c-now;
        LL a=2*r-3*c;
        if (a<=0 || r<=2*a || c<=a) return;
        ans.insert(a);
        return;
    }
    LL t=1;
    FOR(j,0,e[i].se) {
        dfs(i+1,now*t);
        t*=e[i].fi;
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    getPrime(MAXN-1);
    while (scanf("%lld", &n)==1 && n) {
        gete(n);
        ans.clear();
        dfs(0,1);
        if (!SZ(ans)) puts("No Solution Possible");
        else {
            for (auto it=ans.rbegin(); it!=ans.rend(); it++) {
                LL a=*it%MOD;
                printf("Possible Missing Soldiers = %lld\n", 2*a*a%MOD);
            }
        }
        puts("");
    }

    return 0;
}

































