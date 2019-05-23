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
const int MAXN = 1e6+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int m,n,a[12345][12],tot;
map<string,int> mp;
int ID(string& s)
{
    if (mp.count(s)) return mp[s];
    return mp[s]=tot++;
}
bool jdg()
{
    REP(j,n)REP(k,n)if (j<k) {
        map<pii,int> mp;
        REP(i,m) {
            pii t(a[i][j],a[i][k]);
            if (!mp.count(t)) mp[t]=i;
            else {
                puts("NO");
                printf("%d %d\n", mp[t]+1,i+1);
                printf("%d %d\n", j+1,k+1);
                return false;
            }
        }
    }
    return true;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d", &m,&n)==2) {
        while (getchar()!='\n');
        REP(i,m) REP(j,n) {
            string s;
            getline(cin,s,j==n-1 ? '\n':',');
            a[i][j]=ID(s);
        }
        if (jdg()) puts("YES");
    }

    return 0;
}












































