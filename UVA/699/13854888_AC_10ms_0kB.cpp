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






int a[MAXN], kase;

void read(int id)
{
    int t;
    scanf("%d", &t);
    if (t != -1) {
        a[id] += t;
        read(id-1); read(id+1);
    }
}


int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (true) {
        memset(a,0,sizeof(a));
        int id = MAXN/2;
        scanf("%d", &a[id]);
        if (a[id] == -1) break;
        read(id-1); read(id+1);
        int i = MAXN/2;
        while (a[--i]);
        printf("Case %d:\n", ++kase);
        for (i++; a[i+1]; i++) printf("%d ", a[i]);
        printf("%d\n\n", a[i]);
    }
































































    return 0;
}
