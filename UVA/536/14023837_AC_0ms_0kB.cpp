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
const int MAXN  = 2e3+5, INF = ~0U>>1, MOD = ~0U>>1;

char pre[MAXN], in[MAXN];

void build(char* s1, char* s2, int len)
{
    if (len <= 0) return;
    char* p = strchr(s2, *s1);
    build(s1+1, s2, p-s2);
    build(s1+1+(p-s2), p+1, len-1-(p-s2));
    putchar(*s1);
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%s%s", pre, in)) {
        build(pre, in, strlen(pre));
        puts("");
    }

    return 0;
}






















