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
const int INF = 0x3f3f3f3f, MOD = 100000007;
const int MAXN = 1e3+29, MAXM = 1e4+5;

int a[2][MAXN][MAXN],t,n,vis[MAXN][MAXN];
void print()
{
    REP(i,n) {
        REP(j,n) printf("%d\t", a[t][i][j]);
        puts("");
    }
    puts("");
}
void f(string& buf)
{
    stringstream ss(buf);
    stack<string> op;
    string s;
    while (ss>>s) op.push(s);
    while (!op.empty()) {
        s=op.top(); op.pop();
        bool inv=false;
        if (s.back()=='-') inv=true, s.pop_back();
        if (s=="rot") {
            if (!inv) {
                REP(i,n)REP(j,n) a[t^1][n-1-j][i]=a[t][i][j];
            } else {
                REP(i,n)REP(j,n) a[t^1][i][j]=a[t][n-1-j][i];
            }
        } else if (s=="sym") {
            REP(i,n)REP(j,n) a[t^1][i][n-1-j]=a[t][i][j];
        } else if (s=="bhsym") {
            REP(i,n/2)REP(j,n) a[t^1][i][j]=a[t][i][j];
            FOR(i,n/2,n-1)REP(j,n) a[t^1][i][n-1-j]=a[t][i][j];
        } else if (s=="bvsym") {
            REP(i,n/2)REP(j,n) a[t^1][i][j]=a[t][i][j];
            FOR(i,n/2,n-1)REP(j,n) a[t^1][n/2+n-1-i][j]=a[t][i][j];
        } else if (s=="div") {
            if (!inv) {
                REP(i,n)REP(j,n) a[t^1][(i&1)?n/2+i/2:i/2][j]=a[t][i][j];
            } else {
                REP(i,n)REP(j,n) a[t^1][i][j]=a[t][(i&1)?n/2+i/2:i/2][j];
            }
        } else if (s=="mix") {
            if (!inv) {
                REP(i,n) {
                    if (i&1) {
                        REP(j,n) a[t^1][i][j]=a[t][i-!(j&1)][j/2+n/2];
                    } else {
                        REP(j,n) a[t^1][i][j]=a[t][i+(j&1)][j/2];
                    }
                }
            } else {
                REP(i,n) {
                    if (i&1) {
                        REP(j,n) a[t^1][i-!(j&1)][j/2+n/2]=a[t][i][j];
                    } else {
                        REP(j,n) a[t^1][i+(j&1)][j/2]=a[t][i][j];
                    }
                }
            }
        } else continue;
        t^=1;
    }
}
LL gcd(LL a, LL b){ return b==0 ? a : gcd(b,a%b); }
LL lcm(LL a, LL b){ return a/gcd(a,b)*b; }

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; cin>>T;
    FOR(kase,1,T) {
        cin>>n; cin.get();
        string buf; getline(cin,buf);
        REP(i,n)REP(j,n) a[t][i][j]=i*n+j;
        f(buf);

        LL ans=1;
        REP(i,n)REP(j,n) if (vis[i][j]!=kase) {
            LL cnt=0;
            int x=i, y=j;
            do {
                cnt++;
                vis[x][y]=kase;
                int now=a[t][x][y];
                x=now/n;
                y=now%n;
            } while (!(x==i && y==j));
            ans=lcm(ans,cnt);
        }
        cout<<ans<<endl;
        if (kase<T) cout<<endl;

    }

    return 0;
}




































