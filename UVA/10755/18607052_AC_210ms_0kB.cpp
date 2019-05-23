#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
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
const int MAXN = 1e2+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int A,B,C,kase,b[3];
LL S[22][22][22];
void expand(int i)
{
    REP(j,3) b[j]=i&1, i>>=1;
}
int sign()
{
    int sum=0;
    REP(i,3) sum+=b[i];
    return (sum&1) ? 1:-1;
}
LL sum(int x1, int x2, int y1, int y2, int z)
{
    int dx=x2-x1+1, dy=y2-y1+1, dz=z;
    LL s=0;
    REP(i,8) {
        expand(i);
        s -= sign() * S[x2-b[0]*dx][y2-b[1]*dy][z-b[2]*dz];
    }
    return s;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &A,&B,&C);
        FOR(x,1,A)FOR(y,1,B)FOR(z,1,C) scanf("%lld", &S[x][y][z]);
        FOR(x,1,A)FOR(y,1,B)FOR(z,1,C)FOR(i,1,7) {
            expand(i);
            S[x][y][z] += sign() * S[x-b[0]][y-b[1]][z-b[2]];
        }
        LL ans=-1LL<<60;
        FOR(x1,1,A)FOR(x2,x1,A)FOR(y1,1,B)FOR(y2,y1,B) {
            LL M=0;
            FOR(z,1,C) {
                LL s=sum(x1,x2,y1,y2,z);
                ans=max(ans,s-M);
                M=min(M,s);
            }
        }
        printf("%lld\n", ans);
        if (T) puts("");
    }

    return 0;
}










































