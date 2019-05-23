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
const int MAXN  = 7e4, INF = ~0U>>1, MOD = ~0U>>1;

int n, maxd, kase;

bool dfs(int d, int num[])
{
    //永远不要破坏有序的序列
    int rear[n]; //rear记录了有序的序列[i...j),rear[i] = j
    rear[n-1] = n;
    for (int i = n-2; i >= 0; i--)
        rear[i] = num[i]==num[i+1]-1 ? rear[i+1] : i+1;
    if (rear[0] == n) return true;

    int err = 0; //剪枝
    REP(i,n-1)if(num[i+1] != num[i]+1)err++;
    if (3*d + err > 3*maxd) return false;

    for (int i = 0; i < n; i++) {
        for (int j = rear[i]; j < n; j = rear[j]) {
            for (int k = rear[j];  ; k = rear[k]) {
                int tmp[n];
                FOR(l,0,i-1) tmp[l] = num[l];
                FOR(l,i,j-1) tmp[l+k-j] = num[l]; //根据固定的起点或终点位置可快速确定下标变换
                FOR(l,j,k-1) tmp[l+i-j] = num[l];
                FOR(l,k,n-1) tmp[l] = num[l];
                if (dfs(d+1, tmp)) return true;
                if (k == n) break; //设计上有缺陷，不得不在这里break
            }
        }
    }
    return false;
}

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int num[10];
    while (scanf("%d", &n), n) {
        REP(i,n) scanf("%d", &num[i]);
        for (maxd = 0; maxd < n; maxd++) //maxd从0开始，因为极端数据可能是本身即有序
            if (dfs(0, num)) { printf("Case %d: %d\n", ++kase, maxd); break; }
    }

    return 0;
}
