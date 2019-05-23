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

int T,n,m,nxt[MAXN],cnt;
char a[MAXN],b[MAXN];
void get_next(char* P)
{
    int j=0, k=nxt[0]=-1;
    while (j<m) {
        if (k==-1 || P[j]==P[k]) j++,k++,nxt[j] = P[j]!=P[k] ? k : nxt[k];
        //if (k==-1 || P[j]==P[k]) nxt[++j] = ++k;
        else k = nxt[k];
    }
    nxt[m] = 0;
}
void KMP(char* T, char* P)
{
    int i=0, j=0;
    while (i<n) {
        if (j==-1 || T[i]==P[j]) i++,j++;
        else j = nxt[j];
        if (j==m) cnt++;
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%s", a), a[0] != '#') {
        scanf("%s", b);
        n = strlen(a), m = strlen(b);
        cnt = 0, get_next(b), KMP(a,b);
        printf("%d\n", cnt);
    }

    return 0;
}









































































