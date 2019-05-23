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
const int MAXN = 1e3+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int id[MAXN*MAXN],pos[MAXN];
queue<int> Q[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int n,kase=0;
    while (scanf("%d", &n)==1 && n) {
        printf("Scenario #%d\n", ++kase);
        REP(i,n) {
            int m; scanf("%d", &m);
            REP(j,m) {
                int x; scanf("%d", &x);
                id[x]=i;
            }
            while (!Q[i].empty()) Q[i].pop();
        }
        memset(pos,-1,sizeof(pos));
        int st=0,ed=0;
        char op[11];
        while (scanf("%s", op), op[0]!='S') {
            if (op[0]=='E') {
                int x; scanf("%d", &x);
                int r=pos[id[x]];
                if (~r) Q[r].push(x);
                else {
                    Q[ed].push(x);
                    pos[id[x]]=ed;
                    ed=(ed+1)%n;
                }
            } else {
                int x=Q[st].front(); Q[st].pop();
                printf("%d\n", x);
                if (Q[st].empty()) {
                    pos[id[x]]=-1;
                    st=(st+1)%n;
                }
            }
        }
        puts("");
    }

    return 0;
}












































