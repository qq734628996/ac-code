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

int n, d;
char s[MAXN];

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d", &n, &d), n) {
        scanf("%s", s);
        int i = 0, j = 0;
        for ( ; j < n; j++) {
            if (!i) s[i++] = s[j];
            else if (s[i-1] < s[j]) {
                while (i-1 >= 0 && d && s[i-1] < s[j]) { d--; i--; }
                s[i++] = s[j];
            } else {
                if (j+d == n) d--;
                else s[i++] = s[j];
            }
        }
        s[i] = '\0';
        puts(s);
    }

    return 0;
}











































































