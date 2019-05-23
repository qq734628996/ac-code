#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
#define TR(e,x) for(auto e = x.begin(); e != x.end(); e++)
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
const int MAXN = 4e4+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 1e8+7;

int vis[MAXN], prime[MAXN], tot, ans[MAXN], L, R;
void sieve(int n)
{
    FOR(i,2,n) {
        if (!vis[i]) prime[tot++] = i;
        REP(j,n) {
            if (i*prime[j] > n) break;
            vis[i*prime[j]] = 1;
            if (i%prime[j] == 0) break;
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    sieve(sqrt(1e9));
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &L, &R);
        int id = 0;
        FOR(i,L,R) {
            int x = i, sum = 1;
            REP(j,tot) {
                if (x%prime[j] == 0) {
                    int cnt = 0;
                    while (x%prime[j] == 0) {
                        cnt++;
                        x /= prime[j];
                    }
                    sum *= cnt+1;
                }
                if (x == 1) break;
            }
            if (x != 1) sum *= 2;
            ans[i-L] = sum;
            if (ans[i-L] > ans[id]) id = i-L;
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n", L, R, L+id, ans[id]);
    }

    return 0;
}













































































