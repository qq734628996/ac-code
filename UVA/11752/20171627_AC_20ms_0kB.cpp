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
const double eps = 1e-14;
const int MAXN = 1e5+9, MAXM = 1e4+5;

int vis[MAXN],prime[MAXN],tot;
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
struct node {
    ULL x;
    int bas,tms;
    bool operator<(const node& o) const {
        if (x!=o.x) return x<o.x;
        return bas<o.bas;
    }
};
set<node> S;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    puts("1");
    getPrime(MAXN-1);
    FOR(i,2,(1<<16)-1) S.insert({(ULL)i*i*i*i,i,4});
    ULL pre=0;
    while (!S.empty()) {
        node now=*S.begin(); S.erase(S.begin());
        ULL x=now.x;
        int bas=now.bas, tms=now.tms;
        if (x==pre) continue;
        pre=x;
        printf("%llu\n", x);
        for (int i=tms+1; ; i++) {
            if (x>=ULLONG_MAX/bas) break;
            x*=bas;
            if (vis[i]) {
                S.insert({x,bas,i});
                break;
            }
        }
    }

    return 0;
}




































