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
const int MAXN  = 5e3+5, INF = ~0U>>1, MOD = ~0U>>1;

int T, n, a[MAXN];

bool jdg()
{
    for (int i = 0; i <= n-4; i++) {
        for (int l = i+3; l <= n-1; l++) {
            if (a[l] < a[i]) {
                int j = i;
                for (j++; j < l && !(a[j] < a[l]); j++);
                for (j++; j < l && !(a[i] < a[j]); j++);
                if (j < l) return true;
            }
        }
    }
    for (int i = 0; i <= n-4; i++) {
        for (int l = i+3; l <= n-1; l++) {
            if (a[l] > a[i]) {
                int j = i;
                for (j++; j < l && !(a[j] > a[l]); j++);
                for (j++; j < l && !(a[i] > a[j]); j++);
                if (j < l) return true;
            }
        }
    }
    return false;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        REP(i,n) scanf("%d", &a[i]);
        puts(jdg() ? "YES" : "NO");
    }

    return 0;
}







































































