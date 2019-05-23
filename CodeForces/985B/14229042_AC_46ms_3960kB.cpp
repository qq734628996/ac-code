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
const int MAXN  = 2e3+5, INF = ~0U>>1;

char s[MAXN][MAXN];
int cnt[MAXN], m, n;


int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d%d", &m, &n)) {
        REP(i,m) {
            scanf("%s", s[i]);
            REP(j,n) cnt[j] += (s[i][j]-'0');
        }
        REP(i,n)if(!cnt[i]) { puts("NO"); continue; }

        bool ok = false;
        REP(i,m) {
            bool flag = true;
            REP(j,n)if (s[i][j] == '1' && cnt[j] == 1) { flag = false; break; }
            if (flag) { ok = true; break; }
        }
        puts(ok ? "YES" : "NO");
    }


    return 0;
}



































