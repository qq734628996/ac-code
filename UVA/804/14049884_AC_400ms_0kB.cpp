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

int Pn, Tn, maxc, P[MAXN], T[MAXN][MAXN*2], tmp, kase;

void printAns()
{
    printf("Places with tokens:");
    FOR(i,1,Pn)if(P[i])printf(" %d (%d)", i, P[i]);
    puts("\n");
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &Pn), Pn) {
        FOR(i,1,Pn)scanf("%d", &P[i]);
        scanf("%d", &Tn);
        memset(T, 0, sizeof(T));
        FOR(i,1,Tn)while(scanf("%d", &tmp), tmp)T[i][tmp+Pn]++;
        scanf("%d", &maxc);
        int i = 0;
        for ( ; i < maxc; i++) {
            int j = 1;
            for ( ; j <= Tn; j++) {
                bool flag = true;
                FOR(k,1,Pn)if(P[k] < T[j][Pn-k])flag = false;
                if (flag) break;
            }
            if (j <= Tn) {
                FOR(k,1,Pn) {
                    P[k] -= T[j][Pn-k];
                    P[k] += T[j][Pn+k];
                }
            } else {
                printf("Case %d: dead after %d transitions\n", ++kase, i);
                printAns();
                break;
            }
        }
        if (i == maxc) {
            printf("Case %d: still live after %d transitions\n", ++kase, maxc);
            printAns();
        }
    }

    return 0;
}

































