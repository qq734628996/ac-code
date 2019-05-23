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

int n,a[MAXN],l[MAXN],r[MAXN];
bool jdg(int x)
{
    FOR(i,1,n) l[i]=r[i]=0;
    l[1]=a[1];
    r[2]=a[2];
    FOR(i,3,n) {
        if (i&1) {
            int res=x-a[1]-r[i-1];
            if (a[i]<=res) r[i]=a[i];
            else r[i]=res, l[i]=a[i]-res;
        } else {
            int res=a[1]-l[i-1];
            if (a[i]<=res) l[i]=a[i];
            else l[i]=res, r[i]=a[i]-res;
        }
    }
    return l[n];
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n)==1 && n) {
        FOR(i,1,n) scanf("%d", &a[i]);
        if (n==1) {
            printf("%d\n", a[1]);
            continue;
        }
        a[0]=a[n], a[n+1]=a[1];
        int lo=0,hi=0;
        FOR(i,1,n) {
            lo=max(lo,a[i]+a[i+1]);
            hi=max(hi,a[i-1]+a[i]+a[i+1]);
        }
        if (n&1) {
            while (lo<hi) {
                int mi=(lo+hi)>>1;
                if (jdg(mi)) lo=mi+1;
                else hi=mi;
            }
        }
        printf("%d\n", lo);
    }

    return 0;
}










































