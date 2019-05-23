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
const int MAXN  = 5e2+5, INF = ~0U>>1, MOD = ~0U>>1;

int n, a[MAXN], b[MAXN], cnt, id[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n), n) {
        REP(i,n) scanf("%d", &a[i]);
        int ans = INF;
        REP(i,n) {
            cnt = 0;
            memcpy(b, a, sizeof(int) * n);
            memset(id, 0, sizeof(int)*(n+1));
            REP(j,n) id[b[j]] = j;
            REP(j,n) {
                int l = (i+j)%n, r = id[j+1];
                if (l != r) {
                    id[j+1] = l; id[b[l]] = r;
                    b[r] = b[l]; b[l] = j+1;
                    cnt++;
                }
            }
            ans = min(ans, cnt);

            cnt = 0;
            memcpy(b, a, sizeof(int) * n);
            memset(id, 0, sizeof(int)*(n+1));
            REP(j,n) id[b[j]] = j;
            REP(j,n) {
                int l = (i+j)%n, r = id[n-j];
                if (l != r) {
                    id[n-j] = l; id[b[l]] = r;
                    b[r] = b[l]; b[l] = n-j;
                    cnt++;
                }
            }
            ans = min(ans, cnt);\
        }
        printf("%d\n", ans);
    }

    return 0;
}







































































