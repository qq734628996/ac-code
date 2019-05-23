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

namespace IN {
    const int N=100000;
    char str[N],*S=str,*T=str;
    inline char rdc()
    {
        if (S==T) {
            T=(S=str)+fread(str,1,N,stdin);
            if (S==T) exit(0);
        }
        return *S++;
    }
    inline int rd()
    {
        int x=0;
        char t=rdc();
        while (t>'9'||t<'0') t=rdc();
        while ('0'<=t&&t<='9') x=x*10+t-'0', t=rdc();
        return x;
    }
}
int n,L,a[MAXN];
int q[MAXN];
LL cmp(int x1, int x2, int x3, int x4)
{
    return (LL)(a[x2]-a[x1])*(x4-x3) - (LL)(a[x4]-a[x3])*(x2-x1);
}
bool cmp2(int x1, int x3, int x4)
{
    return (LL)(a[x4]-a[x1])*(x4-x3) >= (LL)(a[x4]-a[x3])*(x4-x1);
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (1) {
        n=IN::rd(); L=IN::rd();
        FOR(i,1,n) a[i]=IN::rd(), a[i]+=a[i-1];
        int st=1, ed=0, ansL=1, ansR=L;
        FOR(i,L,n) {
            while (st<ed && cmp2(q[ed-1]-1,q[ed]-1,i-L)) ed--;
            q[++ed]=i-L+1;
            while (st<ed && cmp2(q[st+1]-1,q[st]-1,i)) st++;
            if (cmp(q[st]-1,i,ansL-1,ansR)>0) {
                ansL=q[st];
                ansR=i;
            }
        }
        printf("%.2f\n", (double)(a[ansR]-a[ansL-1])/(ansR-ansL+1));
    }

    return 0;
}







































