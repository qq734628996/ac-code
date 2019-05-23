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
const int MAXN  = 1e3+5, INF = ~0U>>1, MOD = ~0U>>1;

int n, num[10], m, kase;
char a[(2<<7) + 5], buf[10];



int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n), n) {
        printf("S-Tree #%d:\n", ++kase);
        REP(i,n) {
            scanf("%s", buf);
            num[i] = buf[1] - '1';
        }
        scanf("%s%d", a, &m);
        while (m--) {
            scanf("%s", buf);
            int id = 0;
            REP(i,n) if (buf[num[i]] == '1') id += pow(2, n-1-i);
            putchar(a[id]);
        }
        puts("\n");
    }

    return 0;
}






















