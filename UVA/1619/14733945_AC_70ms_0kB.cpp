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
const int MAXN  = 1e5+5, INF = ~0U>>1, MOD = ~0U>>1;

int n, a[MAXN], l[MAXN], r[MAXN], ansL, ansR, kase;
LL s[MAXN];

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
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d", &n)) {
            getchar();
        if (kase++) puts("");
        FOR(i,1,n) scanInt(a[i]), s[i] = s[i-1] + a[i];
        a[0] = a[n+1] = -1;
        for (int i = 1; i <= n; i++) {
            if (!a[i] || a[i-1] < a[i]) l[i] = i-1;
            else {
                int j;
                for (j = l[i-1]; a[j] >= a[i]; j = l[j]);
                l[i] = j;
            }
        }
        for (int i = n; i >= 1; i--) {
            if (!a[i] || a[i+1] < a[i]) r[i] = i+1;
            else {
                int j;
                for (j = r[i+1]; a[j] >= a[i]; j = r[j]);
                r[i] = j;
            }
        }
        LL ans = -1;
        FOR(i,1,n) {
            int L = l[i]+1, R = r[i]-1;
            if ((s[R] - s[L-1]) * a[i] > ans) {
                ans = (s[R] - s[L-1]) * a[i];
                ansL = L, ansR = R;
            }
        }
        printf("%lld\n%d %d\n", ans, ansL, ansR);
    }

    return 0;
}







































































