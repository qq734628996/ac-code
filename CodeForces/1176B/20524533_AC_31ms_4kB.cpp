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
const int MAXN = 5e5+9, MAXM = 2e5+9;



int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);
        vector<int> V[3];
        REP(i,n) {
            int x; scanf("%d", &x);
            V[x%3].pb(x);
        }
        int ans=SZ(V[0]);
        int t1=SZ(V[1]);
        int t2=SZ(V[2]);
        ans+=min(t1,t2);
        int t3=max(t1,t2)-min(t1,t2);
        ans+=t3/3;
        printf("%d\n", ans);
    }

    return 0;
}






























