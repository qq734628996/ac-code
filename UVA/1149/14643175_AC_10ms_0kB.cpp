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

int T, n, L, a[MAXN], kase;

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
        if (kase++) puts("");
        scanInt(n); scanInt(L);
        REP(i,n) scanInt(a[i]);
        sort(a, a+n);
        int i = 0, j = n-1, cnt = 0;
        while (i <= j) {
            while (i<j && a[i]+a[j--]>L) cnt++;
            i++; cnt++;
        }
        printf("%d\n", cnt);
    }

    return 0;
}











































































