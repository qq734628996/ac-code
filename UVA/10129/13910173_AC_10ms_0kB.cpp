#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define TR(e,x) for(auto e = x.begin(); e != x.end(); e++)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n-1) printf("%d ", A[i]); printf("%d\n", A[n-1]); }
#define SHOW2(A,m,n) { REP(i,m) { REP(j,n-1) printf("%d ", A[i][j]); printf("%d\n", A[i][n-1]); } }
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)((x).size())
typedef long long LL;
const int MAXN  = 1e3+5, INF = ~0U>>1, MOD = ~0U>>1;


int T, n, a[26][26], in[26], out[26];
char buf[MAXN];
void euler(int x)
{
    REP(i,26)if(a[x][i]) { a[x][i]--; euler(i); }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        memset(a, 0, sizeof(a));
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        scanf("%d", &n);
        REP(i,n) {
            scanf("%s", buf);
            int ed = strlen(buf) - 1;
            a[buf[0]-'a'][buf[ed]-'a']++;
            in[buf[ed]-'a']++;
            out[buf[0]-'a']++;
        }
        bool flag = true;
        int si = -1;
        REP(i,26)if(in[i]+1 == out[i] || (si==-1 && in[i] && in[i]==out[i])) si = i;
        if (si == -1) flag = false;
        else {
            euler(si);
            REP(i,26)REP(j,26)if(a[i][j]) { flag = false; break; }
        }
        puts(flag ? "Ordering is possible." : "The door cannot be opened.");
    }








    return 0;
}






















