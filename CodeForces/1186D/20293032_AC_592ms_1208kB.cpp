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
const int INF = 0x3f3f3f3f, MOD = 1000000007;
const double PI = acos(-1), EPS = 1e-15;
const int MAXN = 1e5+9, MAXM = 3e3+9;

int n,a[MAXN];
double b[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int n;
    while (scanf("%d", &n)==1) {
        LL sum=0;
        REP(i,n) {
            cin>>b[i];
            a[i]=round(b[i]);
            sum+=a[i];
        }
        REP(i,n) {
            if (sum==0) break;
            if (sum<0) {
                int tmp=ceil(b[i]);
                if (tmp>a[i]) {
                    sum+=tmp-a[i];
                    a[i]=tmp;
                }
            } else {
                int tmp=floor(b[i]);
                if (tmp<a[i]) {
                    sum-=a[i]-tmp;
                    a[i]=tmp;
                }
            }
        }
        REP(i,n) printf("%d\n", a[i]);
    }

    return 0;
}

































