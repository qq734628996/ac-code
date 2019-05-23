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
const int MAXN = 1e6+9, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 10007;

int T,n,m,a[MAXN],b[MAXN],nxt[MAXN];
void get_next(int* P)
{
    int j=0, k=nxt[0]=-1;
    while (j<m) {
        if (k==-1 || P[j]==P[k]) j++,k++,nxt[j] = P[j]!=P[k] ? k : nxt[k];
        else k = nxt[k];
    }
}
int KMP(int* T, int* P)
{
    int i=0, j=0;
    while (j<m && i<n) {
        if (j==-1 || T[i]==P[j]) i++,j++;
        else j=nxt[j];
    }
    return i-j <= n-m ? i-j+1 : -1;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n,&m);
        REP(i,n) scanf("%d", &a[i]);
        REP(i,m) scanf("%d", &b[i]);
        get_next(b);
        printf("%d\n", KMP(a,b));
    }

    return 0;
}









































































