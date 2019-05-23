#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>

#include <iostream>
#include <algorithm>
//#include <unordered_map>
//#include <unordered_set>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
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
const int MAXN = 1e6+9, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 10007;

int T,n,m,nxt[MAXN],ext[MAXN];
char tab[30],rtab[30],a[MAXN],b[MAXN];
void get_next(char* T)
{
    int a=0, p=0;
    nxt[0] = m;
    FOR(i,1,m-1) {
        if (i>=p || i+nxt[i-a]>=p) {
            if (i>=p) p=i;
            while (p<m && T[p]==T[p-i]) p++;
            nxt[i] = p-i;
            a = i;
        } else nxt[i] = nxt[i-a];
    }
}
void extKMP(char* S, char* T)
{
    int a=0, p=0;
    REP(i,n) {
        if (i>=p || i+nxt[i-a]>=p) {
            if (i>=p) p=i;
            while (p<n && p-i<m && S[p]==T[p-i]) p++;
            ext[i] = p-i;
            a = i;
        } else ext[i] = nxt[i-a];
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        scanf("%s%s", tab,b);
        n = m = strlen(b);
        REP(i,n) a[i] = tab[b[i]-'a']; a[n] = '\0';
        get_next(b); extKMP(a,b);
        int ans = n;
        FOR(i,(n+1)/2,n-1) if (i+ext[i]==n) ans = min(ans,i);
        REP(i,26) rtab[tab[i]-'a'] = i+'a';
        REP(i,ans) putchar(b[i]);
        REP(i,ans) putchar(rtab[b[i]-'a']);
        puts("");
    }

    return 0;
}









































































