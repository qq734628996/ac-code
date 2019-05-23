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
const int MAXN = 2e4+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 1000000007;

char op[5];
int n, p[MAXN], r[MAXN];
int Find(int x)
{
    if (p[x] == x) return x;
    int root = Find(p[x]);
    r[x] += r[p[x]];
    return p[x] = root;
}
void Union(int i, int j)
{
    int y = Find(j);
    p[i] = y;
    r[i] = abs(i-j)%1000+r[j];
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        FOR(i,1,n) p[i] = i, r[i] = 0;
        while (scanf("%s", op), op[0] != 'O') {
            if (op[0] == 'I') {
                int x, y; scanf("%d%d", &x, &y);
                Union(x, y);
            } else {
                int x; scanf("%d", &x);
                Find(x);
                printf("%d\n", r[x]);
            }
        }
    }

    return 0;
}












































































