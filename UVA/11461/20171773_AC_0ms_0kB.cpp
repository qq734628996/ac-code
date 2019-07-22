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
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const int INF = 0x3f3f3f3f, MOD = 1000000;
const double EPS = 1e-14;
const int MAXN = 1e5+9, MAXM = 1e4+5;

int vis[MAXN],S[MAXN];
void sieve(int n)
{
    int m=sqrt(n+0.5);
    FOR(i,1,m) vis[i*i]=1;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    sieve(MAXN-1);
    FOR(i,1,MAXN-1) S[i]=S[i-1]+vis[i];
    int a,b;
    while (scanf("%d%d", &a,&b)==2 && a) {
        printf("%d\n", S[b]-S[a-1]);
    }

    return 0;
}




































