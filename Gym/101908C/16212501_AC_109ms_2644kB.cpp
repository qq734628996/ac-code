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
const int MAXN = 1e5+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 1e9+7;

int n, m, t[MAXN], tmp[MAXN];
pii a[MAXN], b[MAXN];

LL cnt;
void merge_sort(int* A, int x, int y, int* T)
{
    if (y-x > 1) {
        int m = x + (y-x)/2;
        int p = x, q = m, i = x;
        merge_sort(A, x, m, T);
        merge_sort(A, m, y, T);
        while (p < m || q < y) {
            if (q >= y || (p < m && A[p] <= A[q])) T[i++] = A[p++];
            else T[i++] = A[q++], cnt += m-p; //统计逆序对
        }
        for (i = x; i < y; i++) A[i] = T[i];
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    { int x, y; scanf("%d%d", &x, &y); }
    scanf("%d%d", &n, &m);
    REP(i,n) scanf("%d%d", &a[i].fi, &a[i].se);
    REP(i,m) scanf("%d%d", &b[i].fi, &b[i].se);
    sort(a, a+n); sort(b, b+m);
    LL ans = 1+n+m+(LL)n*m;
    REP(i,n) t[i] = a[i].se;
    cnt = 0;
    merge_sort(t, 0, n, tmp);
    ans += cnt;
    REP(i,m) t[i] = b[i].se;
    cnt = 0;
    merge_sort(t, 0, m, tmp);
    ans += cnt;
    printf("%lld\n", ans);

    return 0;
}













































































