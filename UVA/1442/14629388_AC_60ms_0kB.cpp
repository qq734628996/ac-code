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
typedef pair<int, int> pii;
const int MAXN  = 1e6+5, INF = ~0U>>1, MOD = ~0U>>1;

int T, n, a[MAXN], b[MAXN], h1[MAXN], h2[MAXN];

inline void scanInt(int&x) {
    char ch;
    while (ch = getchar(), ch < '0' || ch > '9');
    x = ch - '0';
    while (ch = getchar(), ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0';
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanInt(T);
    while (T--) {
        scanInt(n);
        REP(i,n) scanInt(a[i]);
        REP(i,n) scanInt(b[i]);
        h1[0] = b[0];
        for (int i = 1; i < n; i++) {
            if (a[i] > h1[i-1]) h1[i] = a[i];
            else if (b[i] < h1[i-1]) h1[i] = b[i];
            else h1[i] = h1[i-1];
        }
        h2[n-1] = b[n-1];
        for (int i = n-2; i >= 0; i--) {
            if (a[i] > h2[i+1]) h2[i] = a[i];
            else if (b[i] < h2[i+1]) h2[i] = b[i];
            else h2[i] = h2[i+1];
        }
        int ans = 0;
        REP(i,n) ans += min(h1[i], h2[i]) - a[i];
        printf("%d\n", ans);
    }

    return 0;
}











































































