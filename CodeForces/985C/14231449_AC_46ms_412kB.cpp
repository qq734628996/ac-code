#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define TR(e,x) for(auto e = x.begin(); e != x.end(); e++)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n-1) printf("%d ", A[i]); printf("%d\n", A[n-1]); }
#define SHOW2(A,m,n) { REP(i,m) { REP(j,n-1) printf("%d ", A[i][j]); printf("%d\n", A[i][n-1]); } }
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)((x).size())
typedef long long LL;
const int MAXN  = 1e5+5, INF = ~0U>>1;

int n, k, l, a[MAXN];

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d%d%d", &n, &k, &l);
    REP(i,n*k) scanf("%d", &a[i]);
    sort(a, a+n*k);
    int id = (upper_bound(a, a+n*k, a[0]+l)-a)-1;
    if (id+1 < n) { puts("0"); return 0; }

    LL sum = 0;
    int num;
    if (k == 1) num = n;
    else if ((id+1-n)%(k-1)) num = (id+1-n)/(k-1) + 1;
    else num = (id+1-n)/(k-1);

    for (int i = 0; i < num*k; i += k) sum += a[i];
    int last = id;
    for (int i = 0; i < (n-num); i++) sum += a[last--];

    printf("%lld\n", sum);

    return 0;
}



































