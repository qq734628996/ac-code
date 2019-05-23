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
const int MAXN = 1e4+10, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 10007;

struct ant {
    int id,p,d;
    bool operator<(const ant& o) const { return p<o.p; }
} before[MAXN], after[MAXN];
char dirName[][10] = { "L","Turning","R" }, ch;
int K,L,T,n,order[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &K);
    FOR(kase,1,K) {
        printf("Case #%d:\n", kase);
        scanf("%d%d%d", &L,&T,&n);
        REP(i,n) {
            int p,d; scanf("%d %c", &p, &ch);
            d = ch=='L' ? -1 : 1;
            before[i] = (ant){i,p,d};
            after[i] = (ant){0,p+T*d,d};
        }
        sort(before, before+n);
        REP(i,n) order[before[i].id] = i;
        sort(after, after+n);
        REP(i,n-1) if (after[i].p == after[i+1].p) after[i].d = after[i+1].d = 0;
        REP(i,n) {
            int e = order[i];
            if (after[e].p < 0 || after[e].p > L) puts("Fell off");
            else printf("%d %s\n", after[e].p, dirName[after[e].d+1]);
        }
        puts("");
    }

    return 0;
}











































































