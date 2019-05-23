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
const int MAXN = 1e3+5, MAXM = 3e3+5, INF = 0x3f3f3f3f, MOD = 1e9+7;

int S, m, n[11], a[11][11], d[MAXN], cnt[11], r[11];

bool cmp(const int i, const int j)
{
    if (cnt[i] != cnt[j]) return cnt[i] > cnt[j];
    if (n[i] != n[j]) return n[i] < n[j];
    PER(k,n[i]) if (a[i][k] != a[j][k]) return a[i][k] < a[j][k];
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d%d", &S, &m), S) {
        REP(i,m) {
            scanf("%d", &n[i]);
            REP(j,n[i]) scanf("%d", &a[i][j]);
            memset(d, 0, sizeof(d));
            d[0] = 1;
            int V = a[i][n[i]-1]*S;

            REP(_,S) {
                ROF(k,a[i][0],V)REP(j,n[i])
                    if (k-a[i][j] >= 0 && d[k-a[i][j]]) d[k] = 1;
            }

            int t = 0;
            cnt[i] = 0;
            FOR(j,1,V+1) {
                if (d[j]) t++;
                else { cnt[i] = max(cnt[i], t), t = 0; break; }
            }
        }
        REP(i,m) r[i] = i;
        sort(r, r+m, cmp);
        printf("max coverage =%4d :", cnt[r[0]]);
        REP(i,n[r[0]]) printf("%3d", a[r[0]][i]);
        puts("");
    }

    return 0;
}


















































































