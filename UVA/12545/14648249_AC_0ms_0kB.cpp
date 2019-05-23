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
const int MAXN  = 1e2+5, INF = ~0U>>1, MOD = ~0U>>1;

int T, kase;
char a[MAXN], b[MAXN];

int solve()
{
    int len = strlen(a), cnt0[2] = {0}, cnt = 0, ans = 0;
    REP(i,len) {
        if (a[i] == '0') cnt0[0]++;
        if (a[i] == '?') cnt++;
        if (b[i] == '0') cnt0[1]++;
    }
    if (cnt0[0]+cnt < cnt0[1]) return -1;
    REP(i,len) {
        if (a[i] == '?') {
            if (cnt0[0]+cnt == cnt0[1]) { a[i] = '0'; cnt0[0]++; }
            else {
                if (b[i] == '0') { a[i] = '0'; cnt0[0]++; }
                else a[i] = '1';
            }
            cnt--; ans++;
        }
    }
    if (cnt0[0] > cnt0[1]) {
        REP(i,len) {
            if (a[i]=='0' && b[i]=='1') {
                a[i] = '1';
                ans++;
                if (--cnt0[0] == cnt0[1]) break;
            }
        }
    }
    REP(i,len) if (a[i] != b[i]) cnt++;
    ans += cnt/2;
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        scanf("%s%s", a, b);
        printf("Case %d: %d\n", ++kase, solve());
    }

    return 0;
}











































































