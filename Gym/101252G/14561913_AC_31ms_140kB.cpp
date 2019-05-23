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
typedef pair<int, int> pii;
const int MAXN  = 1e3+5, INF = ~0U>>1, MOD = ~0U>>1;

int T;
char s[MAXN];

int main()
{
//#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        int n = strlen(s);
        if (s[n-1] == 'x' || s[n-1] == 's' || s[n-1] == 'o') {
            printf("%s", s);
            printf("%s\n", "es");
            continue;
        }
        if (s[n-1] == 'f') {
            s[n-1] = 'v';
            printf("%s", s);
            printf("%s\n", "es");
            continue;
        }
        if (s[n-1] == 'y') {
            s[n-1] = 'i';
            printf("%s", s);
            printf("%s\n", "es");
            continue;
        }
        if (n >= 2) {
            if (s[n-2] == 'c' && s[n-1] == 'h') {
                printf("%s", s);
                printf("%s\n", "es");
                continue;
            }
            if (s[n-2] == 'f' && s[n-1] == 'e') {
                s[n-2] = 'v'; s[n-1] = '\0';
                printf("%s", s);
                printf("%s\n", "es");
                continue;
            }
        }
        printf("%s%s", s, "s\n");
    }

    return 0;
}












































































