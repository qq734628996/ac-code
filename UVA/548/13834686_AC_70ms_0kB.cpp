

//#include "Head.h"
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
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define TR(e,x) for(auto e = x.begin(); e != x.end(); e++)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n-1) printf("%d ", A[i]); printf("%d\n", A[n-1]); }
#define SHOW2(A,m,n) { REP(i,m) { REP(j,n-1) printf("%d ", A[i][j]); printf("%d\n", A[i][n-1]); } }
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)((x).size())
typedef long long LL;
const int MAXN  = 1e4+5, INF = ~0U>>1, MOD = ~0U>>1;







const int root = 1;
int a[MAXN], lc[MAXN], rc[MAXN], cnt;
//void newtree() { lc[root] = rc[root] = 0; cnt = root; }
//int newnode() { int u = ++cnt; lc[u] = rc[u] = 0; return u; }

char buf[MAXN];
int in[MAXN], post[MAXN], n, ind, res[MAXN];
int gentree(int l1, int r1, int l2, int r2)
{
    //printf("%d %d %d %d\n", l1, r1, l2, r2);

    if (r1 < l1) return 0;
    int root = ++cnt; //DEBUG(cnt)
    a[root] = post[r2];
    //if (l1 == r1) return root;
    int k; //递归使用全局变量的话可能惹来无穷麻烦
    for (k = l1; k <= r1; k++)
        if (in[k] == post[r2]) break;
        //DEBUG(k)
        //DEBUG((k == r1+1))
    lc[root] = gentree(l1, k-1, l2, l2+k-l1-1);
    rc[root] = gentree(k+1, r1, l2+k-l1, r2-1);
    return root;
}

void getres(int root)
{
    if (!lc[root] && !rc[root]) {
        if (!ind || (res[root] < res[ind] || (res[root] == res[ind] && a[root] < a[ind])))
            ind = root;
        return;
    }
    if (lc[root]) { res[lc[root]] = res[root] + a[lc[root]]; getres(lc[root]); }
    if (rc[root]) { res[rc[root]] = res[root] + a[rc[root]]; getres(rc[root]); }
}







int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d", &in[1])) {
        n = 1;
        while (getchar() != '\n')
            scanf("%d", &in[++n]);
        FOR(i,1,n) scanf("%d", &post[i]);

        cnt = 0;
        gentree(1,n,1,n);

        memset(res, 0, sizeof(res));
        res[root] = a[root]; ind = 0;
        getres(root);

        printf("%d\n", a[ind]);
    }














































    return 0;
}
