#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n) printf("%d%c", A[i],i==n-1?'\n':' '); }
#define SHOW2(A,m,n) { REP(j,m) SHOW1(A[j],n) }
#define pb push_back
#define fi first
#define se second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)((x).size())
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const int INF = 0x3f3f3f3f, MOD = 1000000007;
const double PI = acos(-1), EPS = 1e-15;
const int MAXN = 1e4+9, MAXM = 3e3+9;

int a[11][2],b[11],c[11];
bool jdg(int i)
{
    if (i==7) {
        return  a[b[1]][0^c[b[1]]]==a[b[2]][1^c[b[2]]] &&
                a[b[2]][1^c[b[2]]]==a[b[5]][0^c[b[5]]] &&
                a[b[1]][1^c[b[1]]]==a[b[3]][0^c[b[3]]] &&
                a[b[3]][0^c[b[3]]]==a[b[5]][1^c[b[5]]] &&
                a[b[2]][0^c[b[2]]]==a[b[4]][1^c[b[4]]] &&
                a[b[3]][1^c[b[3]]]==a[b[6]][0^c[b[6]]];
    }
    c[i]=0;
    if (jdg(i+1)) return true;
    c[i]=1;
    if (jdg(i+1)) return true;
    return false;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        FOR(i,1,6)REP(j,2) scanf("%d", &a[i][j]);
        bool ok=false;
        FOR(i,1,6) b[i]=i;
        do {
            if (jdg(1)) {
                ok=true;
                break;
            }
        } while (next_permutation(b+1,b+1+6));
        puts(ok?"YES":"NO");
    }

    return 0;
}


































