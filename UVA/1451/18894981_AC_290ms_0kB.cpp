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
const int MAXN = 1e5+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n,L,a[MAXN];
int q[MAXN];
int cmp(int x1, int x2, int x3, int x4)
{
    return (a[x2]-a[x1-1])*(x4-x3+1) - (a[x4]-a[x3-1])*(x2-x1+1);
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n,&L);
        FOR(i,1,n) scanf("%1d", &a[i]), a[i]+=a[i-1];
        int st=0, ed=0, ansL=1, ansR=L;
        FOR(i,L,n) {
            while (ed-st>1 && cmp(q[ed-2],i-L,q[ed-1],i-L)>=0) ed--;
            q[ed++]=i-L+1;
            while (ed-st>1 && cmp(q[st],i,q[st+1],i)<=0) st++;
            int c=cmp(q[st],i,ansL,ansR);
            if (c>0 || (!c && i-q[st]<ansR-ansL)) {
                ansL=q[st];
                ansR=i;
            }
        }
        printf("%d %d\n", ansL,ansR);
    }

    return 0;
}









































