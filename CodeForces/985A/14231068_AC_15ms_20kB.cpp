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
const int MAXN  = 1e2+5, INF = ~0U>>1;

int a[MAXN];


int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL


    int n; scanf("%d", &n);
    int k = n >> 1;
    REP(i,k) scanf("%d", &a[i]);
    sort(a, a+k);

    int cnt1 = 0, cnt2 = 0;
    REP(i,k) {
        cnt1 += abs(a[i]-(i*2+2));
        cnt2 += abs(a[i]-(i*2+1));
    }

    printf("%d\n", min(cnt1, cnt2));

    return 0;
}



































