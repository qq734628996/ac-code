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
const int INF = 0x3f3f3f3f, MOD = 1000003;
const double PI = acos(-1), EPS = 1e-15;
const int MAXN = 1e3+9, MAXM = 3e3+9;

int a[MAXN],r[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    FOR(i,1,1000) {
        for (int j=i; j<=1000; j+=i) a[j]++;
        r[i]=i;
    }
    sort(r+1,r+1000+1,[](int i, int j){
        if (a[i]!=a[j]) return a[i]<a[j];
        return i>j;
    });
    int T; scanf("%d", &T);
    FOR(kase,1,T) {
        int n; scanf("%d", &n);
        printf("Case %d: %d\n", kase,r[n]);
    }

    return 0;
}

































