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
const int INF = 0x3f3f3f3f, MOD = 1000000007;
const double PI = acos(-1), EPS = 1e-15;
const int MAXN = 1e6+9, MAXM = 3e3+9;

int vis[MAXN],prime[MAXN/10],tot;
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
bool isp(int n)
{
    if (n<2) return false;
    REP(i,tot) {
        if (prime[i]*prime[i]>n) break;
        if (n%prime[i]==0) return false;
    }
    return n!=1;
}
int f(int n){ return n*n+n+41; }
int S[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    getPrime(MAXN-1);
    FOR(i,1,10001) S[i]=S[i-1]+isp(f(i-1));
    int l,r;
    while (scanf("%d%d", &l,&r)==2) {
        l++, r++;
        printf("%.2f\n", 100.0*(S[r]-S[l-1])/(r-l+1)+1e-8);
    }

    return 0;
}

































