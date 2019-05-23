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
const int MAXN  = 1e2+5, INF = 0x3f3f3f3f, MOD = 998244353;

int T, d[MAXN][MAXN], kase;
char s[MAXN];
#define jdg(i,j) ((s[i]=='(' && s[j]==')') || (s[i]=='[' && s[j]==']'))

void print(int i, int j)
{ //根据状态转移方程递归打印解
    if (i > j) return;
    if (i == j) {
        if (s[i]=='(' || s[i]==')') printf("()");
        else printf("[]");
        return;
    }
    int ans = d[i][j];
    if (jdg(i,j) && ans == d[i+1][j-1]) {
        putchar(s[i]); print(i+1, j-1); putchar(s[j]);
        return;
    }
    FOR(k,i,j-1)if(ans == d[i][k] + d[k+1][j]) {
        print(i, k); print(k+1, j);
        return;
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T); getchar();
    while (getchar(), fgets(s, MAXN, stdin)) {
        if (kase++) puts("");
        int n = strlen(s);
        s[--n] = '\0';
        REP(i,n) d[i+1][i] = 0, d[i][i] = 1; //边界条件
        PER(i,n-1)FOR(j,i+1,n-1) { //主循环逆序，副循环顺序（根据状态转移方程决定）
            d[i][j] = n;
            if (jdg(i,j)) d[i][j] = min(d[i][j], d[i+1][j-1]);
            FOR(k,i,j-1) d[i][j] = min(d[i][j], d[i][k]+d[k+1][j]);
        }
        print(0, n-1); //递归打印解！！！
        puts("");
    }

    return 0;
}




















































































