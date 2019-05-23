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
const int MAXN  = 3e2+5, INF = ~0U>>1, MOD = ~0U>>1;

int n, a[MAXN];
char ans[MAXN*MAXN*2];

bool sorted(int st)
{
    REP(i,n) if (a[(st+i)%n] != i+1) return false;
    return true;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n), n) {
        REP(i,n) scanf("%d", &a[i]);
        if (sorted(0)) { puts(""); continue; }
        int i = 0, j = 1, k = 0;
        while (true) {
            if (a[i] == 1 && sorted(i)) break;
            if (a[i] < a[j] || (a[i] == n && a[j] == 1)) {
                ans[k++] = '2';
                i = (i+n-1)%n;
                j = (j+n-1)%n;
            }
            else {
                ans[k++] = '1';
                swap(a[i], a[j]);
            }
        }
        reverse(ans, ans+k);
        ans[k] = '\0';
        puts(ans);
        //SHOW1(a,n)
    }

    return 0;
}










































































