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
const int MAXN = 5e1+9, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 100000007;

int m,n,a[MAXN][MAXN];
int vis[MAXM],prime[MAXM],tot;
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

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    getPrime(MAXM-1);
    int T; scanf("%d", &T);
    FOR(kase,1,T) {
        scanf("%d%d", &m,&n);
        int ans=0;
        REP(i,m) {
            int cnt=0;
            REP(j,n) {
                int x; scanf("%d", &x);
                REP(k,tot) {
                    if (x==1) break;
                    if (x%prime[k]==0) {
                        while (x%prime[k]==0) {
                            x/=prime[k];
                            cnt++;
                        }
                    }
                }
            }
            ans^=cnt;
        }
        printf("Case #%d: %s\n", kase,ans?"YES":"NO");
    }

    return 0;
}




































