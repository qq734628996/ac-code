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
const int MAXN  = 5e5+5, INF = ~0U>>1, MOD = ~0U>>1;

char s[MAXN], t[MAXN];
int n, k, len;

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d%d%s", &n, &k, s);

    len = n-k;
    int id = 1;
    t[0] = s[0];
    for (int i = 1; i < n; i++) {
        while (id > 0 && s[i] > t[id-1] && n-i >= len-(id-1)) id--;
            //DEBUG(id)
        t[id++] = s[i];
    }
    puts(t);

    return 0;
}















































































